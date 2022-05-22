#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 1010;

int a[N][N], vis[N][N], n, m;

int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs (int r, int c)
{
	vis[r][c] = 1;
	for (int i=0; i<4; i++)
	{
		int nr = r+step[i][0];
		int nc = c+step[i][1];
		if (nr<1 || nr>n || nc<1 || nc>m || vis[nr][nc] || a[nr][nc]) continue;
		dfs(nr,nc);
	}
}

signed main()
{
	cin >> n >>  m;
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			char c;
			cin >> c;
			a[i][j] = c=='#';
		}
	}
	int ans = 0;
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			if (!vis[i][j] && !a[i][j]) ans++, dfs(i,j);
		}
	}
	cout << ans << '\n';
}
