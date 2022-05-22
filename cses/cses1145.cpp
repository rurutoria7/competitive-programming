#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
dp[i]: max lis(strictly) end with element i
dp[i] = max(dp[j] | 1<=j<i, a[j]<a[i]) + 1

a[i] greater, dp[j] greater, 

a[i] 越大 越難用

v<int> src;
dp[i] = prev(lower_bound(a[i])).ss+1
*/
const int N = 2e5+10;

int n, a[N], dp[N];
vector<pii> src; //a[i], dp[i], a[i] greater, dp[i] greater

signed main()
{
    liyuu_my_wife
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
    {
        if (src.empty())
        {
            dp[i] = 1;
            src.pb({a[i],dp[i]});
        }
        else if (src.back().ff < a[i])
        {
            dp[i] = src.back().ss+1;
            src.pb({a[i],dp[i]});
        }
        else if (src.begin()->ff >= a[i])
        {
            dp[i] = 1;
            *src.begin() = {a[i], dp[i]};
        }
        else
        {
            dp[i] = prev(lower_bound(src.begin(), src.end(), pii{a[i],0}))->ss+1;
            *lower_bound(src.begin(), src.end(), pii{a[i],0}) = {a[i], dp[i]};
        }
    }
    int ans = 0;
    rep(i,1,n) ans = max(ans, dp[i]);
    cout << ans << '\n';
}
