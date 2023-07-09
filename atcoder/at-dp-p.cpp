#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, M = 1e9+7;

vector<int> G[N];
int dp[N][2], n;

void dfs(int u, int p)
{
	dp[u][0] = dp[u][1] = 1;
	for (auto v: G[u])
	{
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] = (dp[u][0]*(dp[v][0]+dp[v][1]))%M;
		dp[u][1] = (dp[u][1]*dp[v][0])%M;
	}
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
	dfs(1,1);
	cout << (dp[1][0] + dp[1][1])%M << '\n';
}
