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

vector<int> G[N];
int n, m, vis[N], ind[N];
vector<int> ans;

int topo()
{
	int res = 0;
	queue<int> q;
	rep(i,1,n) if (!ind[i]) q.push(i);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		ans.pb(u);
		res++;
		for (auto v: G[u])
		{
			ind[v]--;
			if (!ind[v])
				q.push(v);
		}
	}
	return res == n;
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
	if (!topo())
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		for (auto x: ans)
			cout << x << ' ';
		cout << '\n';
	}
}
