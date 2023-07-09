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

const int N = 2e4+10;

vector<int> G[N];
int sz[N], n, zx;

void dfs1(int u, int p=0)
{
	sz[u] = 1;
	for (auto v: G[u])
		if (v != p)
			dfs1(v, u), sz[u] += sz[v];	
}

void dfs2(int u, int p=0)
{
	int mx = sz[1] - sz[u];
	for (auto v: G[u])
		if (v != p)
			mx = max(mx, sz[v]), dfs2(v, u);
	if (mx <= n/2) zx = u;
}

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
	dfs1(1);
	dfs2(1);
	cout << zx << '\n';
}
