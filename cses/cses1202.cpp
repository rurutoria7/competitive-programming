#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, M = 1e9+7;

int n, m;
vector<pii> G[N]; // {w, v}

int dis[N], mnstep[N], mxstep[N], posb[N], vis[N];
vector<int> topo;

void dijks()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; //{dis, u}
    pq.push({0,1});
    memset(dis, 0x3f, sizeof(dis));
    memset(mnstep,0x3f,sizeof(mnstep)), mnstep[1] = 0;
    mxstep[1] = 0;
    posb[1] = 1;    
    dis[1] = 0;
    while(pq.size())
    {
        int u = pq.top().ss, d = pq.top().ff;
        pq.pop();
        if (!vis[u])
        {
            vis[u] = 1;
            topo.pb(u);
            for (auto e: G[u])
            {
                if (dis[e.ss] > d+e.ff)
                {
                    dis[e.ss] = d+e.ff;
                    pq.push({dis[e.ss], e.ss});
                }
            }
        }
        
    }
}

void dp()
{
    for (auto u: topo)
    {
        for (auto e: G[u])
        {
            int w = e.ff, v = e.ss;
            if (dis[v] == w+dis[u])
            {
                mnstep[v] = min(mnstep[v], mnstep[u]+1);
                mxstep[v] = max(mxstep[v], mxstep[u]+1);
                posb[v] = (posb[v]+posb[u])%M;
            }
        }
    }
}

signed main()
{
    mothersrosario
    cin >> n >> m;
    rep(i,1,m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w,v});
    }
    dijks();
    dp();
    cout << dis[n] << ' ' << posb[n] << ' ' << mnstep[n] << ' ' << mxstep[n] << '\n';
}