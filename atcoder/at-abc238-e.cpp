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

int n, q, vis[N];
vector<int> G[N];

void dfs(int u)
{
	vis[u] = 1;
	for (auto v: G[u])
		if (!vis[v])
			dfs(v);	
}

signed main()
{
	cin >> n >> q;
	rep(i,1,q)
	{
		int u, v;
		cin >> u >> v, u--;
		G[u].pb(v);
		G[v].pb(u);
	}	
	dfs(0);
	cout << (vis[n]? "Yes":"No") << '\n';
}
