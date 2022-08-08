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

const int N = 3e5+10;

int c[N];
vector<int> G[N];

int n, m;

struct DSU 
{
    int sz[N], p[N];
    
    void init()
    {
        rep(i,1,n)
        {
            sz[i] = 1;
            p[i] = i;
        }
    }
    int find(int x){ return (p[x]==x? x : p[x]=find(p[x])); }
    void U(int x, int y)
    {
        x = find(x), y = find(y); //merge x -> y
        if (x == y) return;
        sz[y] += sz[x];
        p[x] = y;
    }
    int size(int x){ return sz[find(x)]; }
} dsu;

signed main()
{
    lyx_my_wife
    cin >> n >> m;
    rep(i,1,n) cin >> c[i];

    dsu.init();

    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v])
            dsu.U(u,v);
        G[u].pb(v);
        G[v].pb(u);
    }

    int ans = 1;
    rep(i,1,n)
    {
        set<int> rt;
        map<int,int> cnt;
        for (auto v: G[i])
        {
            if (rt.find(dsu.find(v)) != rt.end()) continue;
            rt.insert(dsu.find(v));
            cnt[c[dsu.find(v)]] += dsu.size(v);
        }

        for (auto kvp: cnt)
        {
            if (c[i] == kvp.ff) ans = max(ans, kvp.ss);
            else ans = max(ans, kvp.ss+1);
        }
    }

    cout << ans << endl;
}