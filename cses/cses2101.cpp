#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
build tree:
    node: 1~n
    edgse: n+1~n+m

    add u, v, eid:
        dsu.find(u) as i
        dsu.find(v) as j
        G[eid].pb(i,j)
        dsu.U(i, eid)
        dsu.U(j, eid)

for all root as rt:
    build_lca(rt)

for quries as u, v:
    cout << lca(u,v)-n << endl;
*/

const int N = 1e5+10, K = 20;

int n, m, q;
vector<int> G[N<<1];

struct DSU 
{
    int n, p[N<<1];
    void init(int _n){ n = _n; rep(i,1,n) p[i] = i; }
    void U(int i, int j){ p[find(i)] = find(j); }
    int find(int i){ return (p[i]==i? i:p[i]=find(p[i])); }
    int same(int i, int j){ return find(i) == find(j); }
} dsu;

struct STable
{
    int n, st[N][K];
    void init(int _n, int *arr)
    {
        n = _n;
        for (int i=0; i<n; i++)
            st[i][0] = arr[i+1];
        for (int k=1; k<K; k++)
            st[k]
    }
} st;

struct LCA
{
    int n, tin[N<<1], tout[N<<1], dep[N<<2], ts;
    void dfs(int u, int d = 0)
    {
        tin[u] = ++ts;
        for (auto v: G[u]) dfs(v,d+1);
        tout[u] = ++ts;
        dep[tin[u]] = d;
        dep[tout[u]] = d;
    }
    void init(int _n)
    {
        n = _n;
        rep(i,1,n)
            if (i == find(i)) 
                dfs(i);
    }
    int query(int i, int j)
    {
        return 
    }
} lca;

signed main()
{
    lyx_my_wife
    cin >> n >> m >> q;
    
    dsu.init(n+m);
    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        int rtu = dsu.find(u);
        int rtv = dsu.find(v);
        int eid = i+n;
        G[eid].pb(rtu);
        G[eid].pb(rtv);
        dsu.U(rtu,eid);
        dsu.U(rtv,eid);
    }

    lca.init(n+m);
    rep(i,1,q)
    {
        int u, v;
        cin >> u >> v;
        if (dsu.find(u) != dsu.find(v)) cout << -1 << endl;
        else cout << lca.query(u, v)-n << endl;
    }
}