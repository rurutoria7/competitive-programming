#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 5e4+10;

int n, m;
vector<int> G[N];
struct Edge {int u, v;};
vector<Edge> edges;

void add_edge (int u, int v)
{
	G[u].pb(edges.size());
	edges.pb({u,v});
	G[v].pb(edges.size());
	edges.pb({v,u});
}

int d[N], l[N], timestamp, bccnt;
void tarjan (int u, int from)
{
	d[u] = l[u] = ++timestamp;
	for (auto e: G[u])
	{
		int v = edges[e].v;
		if (!d[v])
		{
			tarjan(v,e^1);
			l[u] = min(l[u], l[v]);	
			if (l[v] > d[u])
			{
				bccnt++;
			}
		}
		else if (e!=from)
		{
			l[u] = min(l[u], d[v]);
		}
	}
}
int bcc ()
{
	int res = 0;
	rep(i,1,n)
	{
		bccnt = 0;
		if (!d[i]) tarjan(i,-1), res += bccnt+1;
	}	
	return res;
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u,v);
	}
	cout << bcc() << '\n';
}
