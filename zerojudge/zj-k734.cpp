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

const int N = 3e5+10;

int n, m, k, t;
vector<int> G[N], todo;
int ind[N], ans, vis[N];

void topo()
{
	while (todo.size())
	{
		int u = todo.back();
		todo.pop_back();
		
		if (vis[u]) continue;
		vis[u] = 1;

		if (u < n) // box
		{
			ans++;
			for (auto v: G[u])
			{
				todo.pb(v);	
			}
		}
		else // key
		{
			for (auto v: G[u])
			{
				if (vis[v]) continue;
				ind[v]--;
				if (ind[v] <= 0)
				{
					todo.pb(v);
				}
			}
		}
	}
}

signed main()
{
	roadroller
	cin >> n >> m >> k >> t;
	// 1~n: box
	// n+1~n+1+m: key
	
	while (t--)
	{
		int x;
		cin >> x;
		todo.pb(x + n);
	}	

	rep(i,0,n-1)
	{
		rep(j,1,k)
		{
			int x;
			cin >> x;
			G[x + n].pb(i);
			ind[i]++;
		}
	}

	rep(i,0,n-1)
	{
		rep(j,1,k)
		{
			int x;
			cin >> x;
			G[i].pb(x + n);
			ind[x + n]++;
		}	
	}

	/*
	rep(i,1,m+n)
	{
		de(i);
		for (auto v: G[i]) de(v);
		dd
	}
	*/

	topo();
	cout << ans << '\n';
}
