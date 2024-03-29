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

int n, m, vis[N][N];
char G[N][N];

int dfs(int i, int j)
{
	if (i<1 || i>n || j<1 || j>m || G[i][j]=='#' || vis[i][j])
		return 0;
	vis[i][j] = 1;
	dfs(i+1, j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1);
	return 1;		
}

signed main()
{
	cin >> n >> m;
	rep(i,1,n) rep(j,1,m) cin >> G[i][j];
	int ans = 0;
	rep(i,1,n) rep(j,1,m) ans += dfs(i,j);
	cout << ans << '\n';
}
