#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

vector<pii> G[N];
int n, m;

int dis[N];
void dijks (int rt)
{
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	memset(dis,0x3f,sizeof(dis));
	dis[rt] = 0;
	pq.push({dis[rt],rt});
	while(pq.size())
	{
		int u = pq.top().ss;
		int d = pq.top().ff;
		pq.pop();
		if (dis[u] < d) continue;
		for (auto e: G[u])
		{
			if (dis[e.ss] > d+e.ff)
			{
				dis[e.ss] = d+e.ff;
				pq.push({dis[e.ss],e.ss});
			}
		}
	}
}

signed main()
{
	liyuu_my_wife
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb({w,v});
	}
	dijks(1);
	rep(i,1,n)
		cout << dis[i] << ' ' ;
	cout << '\n';
}
