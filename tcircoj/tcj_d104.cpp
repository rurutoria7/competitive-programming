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

int n;
vector<pii> G[N];

int minu, sum[N], sz[N], dp[N];
void dfs1 (int u){
    sz[u] = 1;
    for (auto v: G[u]){
        dfs1(v.ss);
        sum[u] += v.ff*sz[v.ss]+sum[v.ss];
        sz[u] += sz[v.ss];
    }
}
void dfs2 (int u){
    if (u == 0){
        dp[u] = sum[u];
    }
    if (dp[u] <= dp[minu]){
        minu = u;
    }
    for (auto v: G[u]){
        dp[v.ss] = dp[u] + sz[0]*v.ff - sz[v.ss]*2*v.ff;
        dfs2(v.ss);
    }
}

signed main(){
    cin >> n;
    for (int i=1; i<n; i++){
        int x, w;
        cin >> x >> w;
        G[x].pb({w,i});
    }
    dfs1(0);
    dfs2(0);
    cout << minu << '\n' << dp[minu] << '\n';
}