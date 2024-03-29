#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

vector<int> G[N];
int n, dp[N];

int dfs(int u)
{
	int &res = dp[u];
	res = 1;

	for (auto v: G[u])
	{
		res += dfs(v);
	}
	return res;
}

signed main()
{
	cin >> n;
	rep(i,2,n)
	{
		int p;
		cin >> p;
		G[p].pb(i);
	}
	dfs(1);
	rep(i,1,n) cout << dp[i]-1 << ' ';
	cout << '\n';
}
