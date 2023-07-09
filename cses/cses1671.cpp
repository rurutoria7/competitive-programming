#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, m, dis[N];
vector<pii> G[N];

void dijks()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;	
	memset(dis, 0x3f, sizeof(dis));
	pq.push({0, 1});
	dis[1] = 0;
	while(pq.size())
	{
		int u = pq.top().ss;
		int d = pq.top().ff;
		pq.pop();
		if (d > dis[u]) continue;

		for (auto e: G[u])
		{
			int v = e.ss, w = e.ff;
			if (d + w < dis[v])
			{
				dis[v] = d + w;
				pq.push({dis[v], v});
			}
		}
	}
}

signed main()
{
	lyx
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb({w, v});
	}
	dijks();
	rep(i,1,n)
	{
		cout << dis[i] << ' ';
	}
	cout << '\n';
}
