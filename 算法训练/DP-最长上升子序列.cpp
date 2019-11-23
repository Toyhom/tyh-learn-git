#include <iostream>
using namespace std;

int main() {
  int a[100];  //{1 6 8 9 7 5 3 6 2 7 9} 11
  int n;
  cin >> n;

  int seqlen[n + 1];  //状态与子问题
  int seqlen_array[n + 1][n + 1];

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    seqlen[i] = 1;  //边界状态
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j]) {
        seqlen[i] = max(seqlen[i], seqlen[j] + 1);  //转移方程
      }
    }
  }

  while (n > 0) {
    cout << seqlen[n];
    n--;
  }

  system("pause");
}