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

const int N = 1010;

int n, m, rtime[N][N], dis[N][N];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char G[N][N];

vector<pii> mon;
pii st, ed;

void bfs1()
{
	memset(rtime, -1, sizeof(rtime))
	queue<pii> q;
	for(auto x: mon) q.push(x), rtime[x.ff][x.ss] = 0;
	while (q.size())
	{
		pii x = q.front(); q.pop();
		for (int i=0; i<4; i++)
		{
			pii nx = {x.ff + step[i][0], x.ss + step[i][1]};
			if (G[nx.ff][nx.ss] == '#' || dis[nx.ff][nx.ss] >= 0) continue;
			dis[nx.ff][nx.ss] = dis[x.ff][x.ss] + 1;
			q.push(nx);
		}
	}
}
void bfs2()
{


}

signed main()
{
	cin >> n >> m;
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			cin >> G[i][j];
			if (G[i][j] == 'A')
				st = {i,j};
			if (G[i][j] == 'M')
				mon.pb({i,j});
		}
	}
	bfs1(); // find reach time
	if (bfs2())
	{
		cout << "YES\n" << dis[ed.ff][ed.ss] << '\n';
		traceroute(ed);
	}
}
