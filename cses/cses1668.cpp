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

int n, m, colo[N];

vector<int> G[N];

int dfs(int u, int c=1)
{
	if (colo[u]) return c == colo[u];
	colo[u] = c;
	for (auto v: G[u])
		if (!dfs(v, (c==1? 2:1)))
				return 0;
	return 1;
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans = 1;
	rep(i,1,n)
		if (!colo[i])
		{
			int ouo = dfs(i);
			ans &= ouo;
		}
	if (ans)
		rep(i,1,n) cout << colo[i] << ' ';
	else
		cout << "MANY";
	cout << '\n';
}
