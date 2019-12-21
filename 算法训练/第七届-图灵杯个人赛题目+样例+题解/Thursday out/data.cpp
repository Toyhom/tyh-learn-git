#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int T, n, x;
int a[MAXN];
int main()
{
    freopen("2.in", "w", stdout);
    srand(time(0));
    int T = 10;
    printf("%d\n", T);
    //data 1
    // while (T--)
    // {
    //     n = rand() % 100 + 10;
    //     n = MAXN - n;
    //     int mod = rand() % MAXN;
    //     x = rand() % mod + 1;
    //     printf("%d %d\n", n, x);
    //     for (int i = 1; i <= n; i++)
    //         printf("%d ", rand() % 1001);
    //     puts("");
    // }
    //data 2
    while (T--)
    {
        n = rand() % 100 + 10;
        n = MAXN - n;
        printf("%d %d\n", n, T + 1);
        for (int i = 1; i <= n; i++)
            printf("%d ", rand() % 1001);
        puts("");
    }
    return 0;
}