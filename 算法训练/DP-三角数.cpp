#include <iostream>
using namespace std;
int maxsum[100][100];

//无后效性

int main()
{
    int n;
    cin >> n;
    int num[100][100];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> num[i][j];
            maxsum[i][j] = 0;  //状态与子问题
        }
    }

    for (int j = 1; j <= n; j++)
    {
        maxsum[n][j] = num[n][j];  //边界状态
    }

    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++){
            maxsum[i][j] = max(maxsum[i + 1][j], maxsum[i + 1][j + 1]) + num[i][j];   //状态转移方程
        }
    }

    cout << maxsum[1][1];
    system("pause");
    return 0;
}
