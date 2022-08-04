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

const int N = 5e5+10, M = 1e9+7;
int sum[N], ans, n, a[N];

signed main()
{
    lyx_my_wife
    cin >> n;
    rep(i,1,n) cin >> a[i];
    for (int i=n; i>0; i--)
    {
        int dp = (1+sum[a[i]-2]+sum[a[i]-1]+sum[a[i]]+sum[a[i]+1]+sum[a[i]+2])%M;
        ans += dp;
        ans %= M;
        sum[a[i]] += dp;
        sum[a[i]]  %= M;
    }
    cout << ans << '\n';
}
/*
dp[i]: posb stand in i to n

dp[i] = 1+ sum{dp[j]| abs(a[i]-a[j])<=2}

sum[x]: all dp of a[x]
*/