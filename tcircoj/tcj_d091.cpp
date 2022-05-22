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

const int N = 5e4+10;

vector<int> G[N];
int w[N], n, m, vis[N], ans;

int dfs (int u){
    int res = w[u];
    vis[u] = 1;
    for (auto v: G[u]){
        if (!vis[v]){
            res += dfs(v);
        }
    }
    ans = max(ans, res);
    return res;
}

signed main(){
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> w[i];
    for (int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    for (int i=0; i<n; i++){
        if (!vis[i]){
            dfs(i);
        }
    }
    cout << ans << '\n';
}