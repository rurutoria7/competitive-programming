#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define hsiao_8888 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e3+10;

int n, m, str, stc, edr, edc, frr[N][N], frc[N][N], dis[N][N];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char G[N][N];

int can(int d, int r, int c)
{
	if (r<1 || r>n || c<1 || c>m || G[r][c] == '#' || dis[r][c])
		return 0;
	return 1;
}

int bfs()
{
	queue<int> qx, qy;
	qx.push(str);
	qy.push(stc);
	dis[str][stc] = 1;
	while(qx.size())
	{
		int r = qx.front(); qx.pop();
		int c = qy.front(); qy.pop();
		int d = dis[r][c];
		if (G[r][c] == 'B')
		{
			edr = r, edc = c;
			return 1;	
		}
		for (int i=0; i<4; i++)
		{
			int nr = step[i][0] + r;
			int nc = step[i][1] + c;
			if (!can(d+1, nr, nc)) continue;
			dis[nr][nc] = d+1;
			frr[nr][nc] = r;
			frc[nr][nc] = c;
			qx.push(nr), qy.push(nc);
		}
	}
	return 0;
}

void print(int r=edr, int c=edc)
{
	if (r != str || c != stc)
		print(frr[r][c], frc[r][c]);
	if (frr[r][c]-1 == r && frc[r][c] == c)
		cout << 'U';
	if (frr[r][c]+1 == r && frc[r][c] == c)
		cout << 'D';
	if (frr[r][c] == r && frc[r][c]+1 == c)
		cout << 'R';
	if (frr[r][c] == r && frc[r][c]-1 == c)
		cout << 'L';
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> G[i][j];
	rep(i,1,n) rep(j,1,m) if (G[i][j] == 'A') str = i, stc = j;
	if (bfs())
	{
		cout << "YES\n" << dis[edr][edc]-1 << '\n';
		print();
		cout << '\n';
	}
	else cout << "NO\n";
}
