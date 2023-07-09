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

const int N = 5e4+10;

bitset<N> dp[N];
int n, m;
vector<int> G[N];

vector<int> tp;
int ind[N];
void topo()
{
	vector<int> st;
	rep(i,1,n) if (!ind[i]) st.pb(i);
	while (st.size())
	{
		int u = st.back();
		st.pop_back();
		tp.pb(u);
		for (auto v: G[u])
		{
			ind[v]--;
			if (!ind[v])
				st.pb(v);
		}
	}
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		ind[v]++;
		G[u].pb(v);
	}	
	topo();
	for (int i=tp.size()-1; i>=0; i--)
	{
		int u = tp[i];
		dp[u].set(u);
		for (auto v: G[u])
			dp[u] |= dp[v];
	}
	rep(i,1,n)
		cout << dp[i].count() << ' ';
	cout << '\n';
}
