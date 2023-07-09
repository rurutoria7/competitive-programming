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

const int N = 5e3+10;

int n, m, dis[N];
vector<pair<int, pii>> E;

int bellman(int rt)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	for (int i=1; i<=n; i++)
	{
		for (auto e: E)
		{
			int u = e.second.first;
			int v = e.second.second;
			int w = e.first;
			
			if (dis[u] + w < dis[v])
			{
				if (i == n)
				{
					return 1;
				}
				dis[v] = dis[u] + w;
			}
		}
	}
	return 0;
}

signed main()
{
    roadroller
	cin >> n >> m;
	rep(i,1,m)
	{
		int x, y, z, w;
		cin >> x;
		if (x == 1)
		{
			cin >> y >> z >> w;
			// y - z >= w, y >= z + w, z <= y - w;
			E.pb({-w, {y, z}});
		}
		if (x == 2)
		{
			// y - z <= w, y <= z + w
			cin >> y >> z >> w;
			E.pb({w, {z, y}});
		}
		if (x == 3)
		{
		    cin >> y >> z;
			// y - z <= 0, z - y <= 0
			// y <= z + 0, z <= y + 0
			E.pb({0, {y, z}});
			E.pb({0, {z, y}});
		}
	}

	rep(i,1,n)
		E.pb({0, {0, i}});


	if (bellman(0)) cout << "No\n";
	else cout << "Yes\n";
}

