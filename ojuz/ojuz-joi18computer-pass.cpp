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

const int N = 1e5+10, M = 2e5+10;

int n, m, s, t, u, v;
vector<pii> G[N];

int disu[N], disv[N], diss[N], dist[N], vis[N];
int dpu[N], dpv[N], ans;

void dijks(int rt, int dis[N], int fordp=0, int forans=0)
{
    memset(dis, 0x3f, sizeof(disu));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[rt] = 0;
    pq.push({0, rt});

    if (fordp)
    {
        memset(dpu, 0x3f, sizeof(dpu));
        memset(dpv, 0x3f, sizeof(dpv));
    }
    
    while(pq.size())
    {
        int i = pq.top().ss, d = pq.top().ff;
        pq.pop(); 

        if (vis[i]) continue;
        vis[i] = 1;

        if (fordp)
        {
            dpu[i] = min(dpu[i], disu[i]);
            dpv[i] = min(dpv[i], disv[i]);            
        }

        for (auto e: G[i])
        {
            int j = e.ss, w = e.ff;
            if (dis[j] > d+w)
            {
                dis[j] = d+w;
                pq.push({dis[j], j});
                if (fordp) dpu[j] = dpu[i], dpv[j] = dpv[i];
            }
            else if (dis[j] == d+w and fordp)
                dpu[j] = min(dpu[j], dpu[i]), dpv[j] = min(dpv[j], dpv[i]);

        }
    }
}

void bfs(int rt)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(rt);
    while(q.size())
    {
        int i = q.front(); q.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        for (auto e: G[i])
        {
            int w = e.ff, j = e.ss;
            if (diss[j] != diss[i]-w) continue;
            ans = min(ans, dpu[j]+disv[i]);
            ans = min(ans, dpv[j]+disu[i]);
            q.push(j);
        }
    }
}

signed main()
{
    lyx_my_wife
    cin >> n >> m >> s >> t >> u >> v;
    rep(_,1,m)
    {
        int i, j, w;
        cin >> i >> j >> w;
        G[i].pb({w,j});
        G[j].pb({w,i});
    }

    // dijks for disu, disv
    dijks(u,disu);
    dijks(v,disv);
    dijks(s,diss,1);
    ans = disu[v];
    bfs(t);
    cout << ans << '\n';
}