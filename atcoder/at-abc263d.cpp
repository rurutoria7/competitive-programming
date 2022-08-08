#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int dp[N][5], a[N], n, l, r;

signed main()
{
    cin >> n >> l >> r;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
    {
        dp[i][1] = dp[i-1][1] + l;
        dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][3] = min(dp[i-1][3], min(dp[i-1][1], dp[i-1][2])) + r;
    }
    cout << min(dp[n][1], min(dp[n][2], dp[n][3])) << endl;
}
/*
dp[i][1]: 1~i min sum, end with L 
dp[i][2]: 1~i min sum, end with a[i]
dp[i][3]: 1~i min sum, end with R

dp[i][1] = dp[i-1][1] + l
dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + 
dp[i][3] = max(dp[i-1][3], dp[i-1][2], dp[i-1][1])
*/
