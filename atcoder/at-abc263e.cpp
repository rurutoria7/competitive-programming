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

const int N = 2e5+10, M = 998244353;

/*
square: 1, 2, 3, ..., n-2, n-1, n
dice  : n-1, n-2, n-3,  ..., 2, 1, 0 (a[i])

dp[i]: expected value roll dice to n
expected value: dp[j] sum /a[i]

dp[i] = ( dp[i] + dp[i+1] + dp[i+2] + ... + dp[i+a[i]] ) / a[i]

dp[n] = 0
dp[i] = 1 + (a[i])^-1 * (dp[i] + dp[i+1] + dp[i+2] + ... + dp[i+a[i]])
dp[i] = 1 + (a[i])^-1 * (1 + (a[i])^-1 * (dp[i] + dp[i+1] + dp[i+2] + ... + dp[i+a[i]]) + dp[i+1] + dp[i+2] + ... + dp[i+a[i]])
suf[i] = dp[i] + dp[i+1] + ... + dp[n]
dp[i] = 1 + (a[i])^1 * (suf[i+1] - suf[i+a[i]+1] ) + (a[i]^1)
*/

int n, a[N], suf[N], dp[N];

int qpow(int i, int j)
{
    int res = 1;
    for (; j; j>>=1, i = i*i%M)
        if (j&1)
            res = res*i%M;
    return res;
}

signed main()
{
    cin >> n;
    rep(i,1,n-1) cin >> a[i];
    for (int i=n-1; i>0; i--)
    {
        dp[i] = (1 + (qpow(a[i], M-2) * ((suf[i+1] - suf[i+a[i]+1] + 1)%M+M)%M)%M)%M;
        suf[i] = (suf[i+1] + dp[i])%M;
    }
    cout << dp[1] << endl;
}