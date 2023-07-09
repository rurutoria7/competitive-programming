#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10, LG = __lg(N)+5;

int n, q, sz[N];
vector<vector<int>> G(N);

struct LCA
{
    int p[LG][N], dep[N];

    void build(int u)
    {
        sz[u] = 1;
        for (int i=1; i<LG; i++)
            p[i][u] = p[i-1][p[i-1][u]];
        for (auto v: G[u])
            if (v != p[0][u])
                p[0][v] = u, dep[v] = dep[u]+1, build(v), sz[u] += sz[v];
    }
    int query (int x, int y)
    {
        if (dep[x] < dep[y]) swap(x,y); // x deeper
        for (int t=dep[x]-dep[y],j=0; t; t>>=1,j++)
            if (t&1) x = p[j][x];
        
        if (x == y) return x;

        for (int s=LG-1; s>=0; s--)
        {
            if (p[s][x] == p[s][y]);
            else x = p[s][x], y = p[s][y];
        }
        return p[0][x];
    }
} lca;

int inpath(int z, int x, int y) // z in x-y
{
    int l = lca.query(x,y);
    if (lca.query(x,z) == z && lca.query(z,l) == l) return 1;
    if (lca.query(y,z) == z && lca.query(z,l) == l) return 1;
    return 0;
}
int calc(int x, int y) // size of x's son that contains y
{
    if (x == y) return 0;
    for (int s=LG-1; s>=0; s--)
    {
        //de(x), de(y), de(s), dd
        if (lca.dep[x] >= lca.dep[lca.p[s][y]]);
        else y = lca.p[s][y];
    }
    return sz[y];
}


signed main()
{
    lyx
    cin >> n >> q;
    rep(i,2,n)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    lca.build(1);
    rep(i,1,q)
    {
        int x, y, z;
        cin >> x >> y >> z;
        
        int l = lca.query(x,y);
        if (l == z) cout << n - calc(l,x) - calc(l,y) << '\n';
        else if (inpath(z,l,x)) cout << sz[z] - calc(z,x) << '\n';
        else if (inpath(z,l,y)) cout << sz[z] - calc(z,y) << '\n';
        else cout << 0 << '\n';
    }
}