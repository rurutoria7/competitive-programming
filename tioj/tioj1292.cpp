#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e4+10;

int dp[N][2], n; //dp[i][1]: min of tree i, i must be colored
vector<int> G[N];

void f (int u, int p)
{
    for (auto v: G[u])
    {
        if (v != p)
        {
            f(v,u);
            dp[u][0] += dp[v][1];
            dp[u][1] += dp[v][0];
        }
    }
    dp[u][1]++;
    dp[u][0] = min(dp[u][0], dp[u][1]);
}

signed main()
{
    lyx_my_wife
    cin >> n;
    rep(i,2,n)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    f(1,0);
    cout << dp[1][0] << '\n';
}