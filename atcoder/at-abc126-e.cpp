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

int n, m, vis[N];
vector<int> G[N];

int dfs(int u)
{
	if (vis[u]) return 0;
	vis[u] = 1;
	for (auto v: G[u]) dfs(v);
	return 1;
}

signed main()
{
	lyx
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans = 0;
	rep(i,1,n) ans += dfs(i);
	cout << ans << '\n';
}
