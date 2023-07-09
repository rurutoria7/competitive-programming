#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int n, m, dp[1010][1010];
char s[1010];

int f(int l, int r)
{
    if (dp[l][r] < 0)
    {
        if (l >= r)
            dp[l][r] = 0;
        else if (s[l] == s[r])
            dp[l][r] = f(l+1, r-1);
        else
        {
            dp[l][r] = f(l+1, r) + 1;
            if (f(l,r-1) < dp[l][r])
                dp[l][r] = f(l,r-1) + 1;
        }
    }
    return dp[l][r];
}

signed main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%s", &n, &m, s);
    if (f(0, n-1) <= m)
        printf("Yes\n");
    else
        printf("No\n");
}