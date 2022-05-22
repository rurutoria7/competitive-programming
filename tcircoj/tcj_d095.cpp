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

const int N = 1e4+10;

int n, m, op, ed;
int mnd[N], mxd[N];
vector<pii> G[N];

void dfs (int u){
    if (u == op){
        mnd[u] = mxd[u] = 0;
        return;
    }
    if (mnd[u] != 0) return;
    mnd[u] = 1e18;
    mxd[u] = -1;
    for (auto v: G[u]){
        dfs(v.ss);
        mnd[u] = min(mnd[u], mnd[v.ss]+v.ff);
        mxd[u] = max(mxd[u], mxd[v.ss]+v.ff);
    }
}

signed main(){
    minamisan
    cin >> n >> m >> op >> ed;
    for (int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[v].pb({w,u});
    }
    dfs(ed);
    if (mnd[ed]<1e18) cout << mnd[ed] << '\n' << mxd[ed] << '\n';
    else cout << "No path\nNo path\n";
}