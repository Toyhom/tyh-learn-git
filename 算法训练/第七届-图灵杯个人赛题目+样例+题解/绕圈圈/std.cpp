#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (n > m)
            swap(n, m);
        if (n == 1)
        {
            if (m == 1)
                puts("1");
            else
                puts("2");
        }
        else if (n == 2)
            printf("%d\n", n * m);
        else
            printf("%d\n", 2 * (n + m - 2));
    }
    return 0;
}