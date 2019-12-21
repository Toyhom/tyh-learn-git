#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int T, n, x;
int a[MAXN], sum[MAXN];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &x);
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
        int ans = 0, tmp = n + 1;
        for (int i = 1; i <= n; i++)
        {
            int l = i, r = n + 1;
            int tmp = n + 1;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (sum[mid] - sum[i - 1] >= x)
                    r = mid, tmp = mid;
                else
                    l = mid + 1;
            }
            ans += (n - tmp + 1) % MOD;
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}