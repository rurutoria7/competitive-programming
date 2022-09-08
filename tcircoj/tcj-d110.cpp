#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, dp[N][3], w[N];
vector<int> G[N];

void dfs (int u, int p){
    if (u!=1 && G[u].size()==1){
        dp[u][0] = 0;
        dp[u][1] = w[u];
        dp[u][2] = w[u];
        return;
    }

    dp[u][2] = w[u];
    for (auto v: G[u]){
        if (v == p) continue;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][2] += dp[v][0];
    }
    dp[u][1] = 9e18;
    for (auto v: G[u]){
        if (v == p) continue;
        dp[u][1] = min(dp[u][1], dp[u][0]-dp[v][1]+dp[v][2]);
    }
    dp[u][1] = min(dp[u][1], dp[u][2]);
    dp[u][0] = min(dp[u][0], dp[u][1]);
}

signed main(){
    minamisan
    cin >> n;
    rep(i,1,n) cin >> w[i];
    rep(i,2,n){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,1);
    cout << dp[1][0] << '\n';
}