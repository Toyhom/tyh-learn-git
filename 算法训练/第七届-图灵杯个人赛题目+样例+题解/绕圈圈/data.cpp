#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int main()
{
    freopen("1.in", "w", stdout);
    srand(time(0));
    T = rand();
    T = T % 100 + 1;
    T += 900;
    printf("%d\n", T);
    //data 1
    while (T--)
    {
        n = (rand() * rand() % 1000 + 1007) % 1000 + 1;
        m = (rand() * rand() % 1000 + 1007) % 1000 + 1;
        printf("%d %d\n", n, m);
    }
    //data 2
    // int flag = 2;
    // while (T--)
    // {
    //     if (flag == 2)
    //         printf("%d %d\n", 1, 1), flag = 1;
    //     else
    //         n = rand() % 1000 + 1, printf("%d %d\n", n, flag % 2 ? 1 : 2), flag ^= 1;
    // }
    return 0;
}