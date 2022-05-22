#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

vector<int> G[N];
int n, m, ind[N];

int dp[N], src[N];

vector<int> tp, noin;
void topo()
{
	rep(i,1,n)
		if (ind[i] == 0)
			noin.pb(i);
	while (noin.size())
	{
		int u = noin.back();
		tp.pb(u);
		noin.pop_back();
		for (auto v: G[u])
		{
			ind[v]--;
			if (ind[v] == 0)
				noin.pb(v);
		}
	}
}

void track (int u)
{
	while (u)
	{
		cout << u << ' ';
		u = src[u];
	}
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		ind[v]++;
	}
	topo();
	for (int i=tp.size()-1; i>=0; i--)
	{
		int u = tp[i];
		if (u == n)
		{
			dp[u] = 1;
		}
		else
		{
			dp[u] = -1e9;
			for (auto v: G[u])
			{
				if (dp[v] > dp[u])
				{
					dp[u] = dp[v];
					src[u] = v;
				}
			}
			dp[u]++;
		}
	}
	if (dp[1] < 0)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << dp[1] << '\n';
		track(1);
	}
}