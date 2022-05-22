#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 510;

int dis[N][N];

int n, m, q;

signed main()
{
	cin >> n >> m  >> q;
	rep(i,1,n) 
		rep(j,1,n)
			dis[i][j] = (i==j? 0:2e18);
	while(m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = min(dis[u][v],w);
	}
	rep(k,1,n)
	{
		rep(j,1,n)
		{
			rep(i,1,n)
			{
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		cout << (dis[u][v]>1e18? -1:dis[u][v]) << '\n';
	}
}
