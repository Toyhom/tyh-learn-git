
// 数字三角形POJ1163
// 在上面的数字三角形中寻找一条从顶部到底边的路径，使得
// 路径上所经过的数字之和最大。路径上的每一步都只能往左下或
// 右下走。只需要求出这个最大和即可，不必给出具体路径。
// 三角形的行数大于1小于等于100，数字为 0 - 99

// 输入格式 : 5 //三角形行数。下面是三角形
// 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5 要求输出最大和

#include <iostream>
using namespace std;
int maxsum[100][100];

//无后效性

int main() {
  int n;
  cin >> n;
  int num[100][100];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> num[i][j];
      maxsum[i][j] = 0;  //状态与子问题
    }
  }

  for (int j = 1; j <= n; j++) {
    maxsum[n][j] = num[n][j];  //边界状态
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      maxsum[i][j] = max(maxsum[i + 1][j], maxsum[i + 1][j + 1]) +
                     num[i][j];  //状态转移方程
    }
  }

  cout << maxsum[1][1];
  system("pause");
  return 0;
}
