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

vector<pii> G[N];

int h[N], hw[N], n;

void dfs (int u, int p){
    for (auto v: G[u]){
        if (v.ss == p){
            continue;
        }
        dfs(v.ss,u);
        h[u] = max(h[u], h[v.ss]+1);
        hw[u] = max(hw[u], hw[v.ss]+v.ff);
    }
}

signed main(){
    minamisan
    cin >> n;
    rep(i,1,n-1){
        int x, w;
        cin >> x >> w;
        G[i].pb({w,x});
        G[x].pb({w,i});
    }
    dfs(0,0);
    cout << hw[0] << '\n' << h[0] << '\n';
}
