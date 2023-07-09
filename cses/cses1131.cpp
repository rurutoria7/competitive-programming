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

const int N = 2e5+10;

int n, h1[N], h2[N], ans;
vector<int> G[N];

void dfs(int u, int p)
{
	for (auto v: G[u])
	{
		if (v == p) continue;
		dfs(v, u);
		if (h1[v]+1 >= h1[u]) h2[u] = h1[u], h1[u] = h1[v]+1;
		else if (h2[v]+1 > h2[u]) h2[u] = h2[v]+1;
	}	
	ans = max(ans, h1[u]+h2[u]);
}

ruru
ruru7


signed main()
{
	cin >> n;
	rep(i,2,n)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << '\n';
}
