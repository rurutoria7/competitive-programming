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

const int N = 1e5+10;
typedef pair<int,pii> Node; //{w, {u, coupon}}

vector<pii> G[N];
int n, m;

priority_queue<Node, vector<Node>, greater<Node>> pq;
int dis[N][2];
void spfa (int rt)
{
    memset(dis,0x3f,sizeof(dis));
    dis[rt][0] = 0;
    pq.push({0,{rt,0}});
    while (pq.size())
    {
        int u = pq.top().ss.ff;
        int d = pq.top().ff;
        int coup = pq.top().ss.ss;
       // de(u), de(d), de(coup), dd
        pq.pop();
        if (dis[u][coup] < d) continue;
        for (auto e: G[u])
        {
            int v = e.ss;
            int w = e.ff;
            if (dis[v][coup] > d+w)
            {
                dis[v][coup] = d+w;
                pq.push({d+w, {v,coup}});
            }
            if (coup==0 && dis[v][1] > d+w/2)
            {
                dis[v][1] = d+w/2;
                pq.push({d+w/2, {v,1}});
            }
        }

    }
}

signed main()
{
    cin >> n >> m;
    rep(i,1,m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w,v});
    }
    spfa(1);
    cout << dis[n][1] << '\n';
}