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

const int N = 2510, M = 5010;

struct Edges {int u, v, w;} edges[M];
vector<pii> rG[N], G[N];
int n, m;

int vis[N], vis2[N];
void dfs (int u, vector<pii> *adj , int *v)
{
    v[u] = 1;
    for (auto e: adj[u])
    {
        if (v[e.ss]) continue;
        dfs(e.ss,adj,v);
    }
}

int relaxed[N], dis[N];
int bellman (int rt)
{
    memset(dis,0x3f,sizeof(dis));
    dis[rt] = 0;
    rep(j,1,n)
    {
        rep(i,1,m)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (!vis[u] || !vis[v]) continue;
            if (!vis2[u] || !vis2[v]) continue;
            if (dis[v] > dis[u]+w)
            {
                if (j == n) return 1;
                dis[v] = dis[u]+w;
            }
        }
    }
    return 0;
}

signed main()
{
    cin >> n >> m;
    rep(i,1,m)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w *= -1;
        rG[edges[i].v].pb({edges[i].w, edges[i].u});
        G[edges[i].u].pb({edges[i].w, edges[i].v});

    }
    dfs(1,G,vis);
    dfs(n,rG,vis2);
    int nync = bellman(1);
    cout << (nync? -1:-dis[n]) << '\n';
}
