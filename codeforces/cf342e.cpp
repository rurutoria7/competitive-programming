#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define las(x) (prev(x.end()))
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, m;
vector<int> G[N];

struct CTD
{
	int rem[N], ctfa[N], sz[N];
	int find_c (int u, int p)
	{
		for (auto v: G[u])
		{
			
		}
	}
	void build_ctfa (int u, int _ctfa)
	{
		build_sz(u);
		int c = find_c(u);	
		for (auto v: G[c])
		{
			if (rem[v]) continue;
			build_ctfa(v,c);
		}
	}
	void init()
	{
		build_ctfa(1);
	}	
} ctd;

signed main()
{
	cin >> n >> m;
	rep(i,2,n)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);	
	}
	ctd.init();
	rep(i,1,m)
	{
		int o, u;
		cin >> o >> u;
		if (o == 1)
			ctd.update(u);
		else
			ctd.update(u);
	}	
}
