#include <bits/stdc++.h>
#define cmax(a,b) a = max(a,b)
#define cmin(a,b) a = min(a,b)
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
int n, m, k;

multiset<int> dis[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dijks (int rt)
{
	dis[rt].insert(0);
	pq.push({0,rt});
	while(pq.size())
	{
		int u = pq.top().ss;
		int d = pq.top().ff;	
		pq.pop();
		if (d > *dis[u].rbegin()) continue;
		for (auto e: G[u])
		{
			int v = e.ss;
			int nd = d+e.ff;
			if (dis[v].size()<k || *dis[v].rbegin()>nd)
			{
				dis[v].insert(nd);
				while (dis[v].size() > k) dis[v].erase(prev(dis[v].end()));
				pq.push({nd,v});
			}
		}
	}
}

signed main()
{
	cin >> n >> m >> k;
	rep(i,1,m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb({w,v});
	}
	dijks(1);
	for (auto x: dis[n])
		cout << x << ' ';
	cout << '\n';
}
