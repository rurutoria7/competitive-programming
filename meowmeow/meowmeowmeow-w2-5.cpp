#include <bits/stdc++.h>
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

const int N = 15;

int t, n, m, cost[N][N], opx[2], opy[2], edx[2], edy[2];

struct Search
{
	int vis[N][N], ans, has_sol = 0;
	int cnt = 0;
	int step[2][6][2] = 
	{
		{{-1, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1}},
		{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {0, -1}}
	};

	void debug(int (*v)[15])
	{
		dd
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				cout << v[i][j] << ' ';
			}
			dd
		}
		
	}
	int dis[N][N];
	int dijks(int rx, int ry, int tx, int ty)
	{
		priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>> > pq;
		memset(dis, 0x3f, sizeof(dis));
		dis[rx][ry] = cost[rx][ry];
		pq.push({cost[rx][ry], {rx, ry}});
		
		while (pq.size())
		{
			int i = pq.top().ss.ff;
			int j = pq.top().ss.ss;
			int d = pq.top().ff;
			pq.pop();

			for (int fw=0; fw<6; fw++)
			{
				int nr = step[i&1][fw][0] + i;
				int nc = step[i&1][fw][1] + j;

				if (nr < 1 || nr > n || nc < 1 || nc > m || vis[nr][nc])
					continue;

				if (dis[nr][nc] > d + cost[nr][nc])
				{
					dis[nr][nc] = d + cost[nr][nc];
					pq.push({dis[nr][nc], {nr, nc}});
				}
			}
		}	
		return dis[tx][ty];
	}
	int triangle(int i, int j)
	{
		for (int x=0, y=1; x<6; x++, y=(y+1)%6)
		{
			int p0x = i + step[i&1][x][0];
			int p0y = j + step[i&1][x][1];
			int p1x = i + step[i&1][y][0];
			int p1y = j + step[i&1][y][1];
			if (!vis[p0x][p0y] || !vis[p1x][p1y])
				continue;
			if (vis[p0x][p0y] == vis[i][j] - 1 && vis[p1x][p1y] == vis[i][j] - 2)
				return 1;
			if (vis[p0x][p0y] == vis[i][j] - 2 && vis[p1x][p1y] == vis[i][j] - 1)
				return 1;				
		}
		return 0;
	}
	void dfs(int i, int j, int sum)
	{
		if (sum + dijks(i, j, edx[0], edy[0]) + dijks(opx[1], opy[1], edx[1], edy[1]) >= ans)
			return;
		if (triangle(i, j))
			return;
		sum += cost[i][j];
		if (i == edx[0] && j == edy[0])
		{
			ans = dijks(opx[1], opy[1], edx[1], edy[1]) + sum;
			if (ans < 1e5) has_sol = 1;
			//debug(vis);
			return;
		}
		for (int fw=0; fw<6; fw++)
		{
			int nr = step[i&1][fw][0] + i;
			int nc = step[i&1][fw][1] + j;

			if (nr < 1 || nr > n || nc < 1 || nc > m || vis[nr][nc]) 
				continue;

			if ((nr == edx[1] && nc == edy[1]) || (nr == opx[1] && nc == opy[1]))
				continue;

			vis[nr][nc] = vis[i][j] + 1;
			dfs(nr, nc, sum);
			vis[nr][nc] = 0;
		}
	}
	int solve()
	{
		ans = 1e5;
		has_sol = 0;
		cnt = 0;
		vis[opx[0]][opy[0]] = 1;
		dfs(opx[0], opy[0], 0);
		vis[opx[0]][opy[0]] = 0;
		if (has_sol) return ans;
		else return -1;
	}
} slv;

signed main()
{
	roadroller
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		rep(i,0,1) cin >> opx[i] >> opy[i] >> edx[i] >> edy[i];
		rep(i,1,n) rep(j,1,m) cin >> cost[i][j];
		cout << slv.solve() << '\n';
	}
}
/*
1
5 10
1 1 5 10
5 1 1 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10



*/