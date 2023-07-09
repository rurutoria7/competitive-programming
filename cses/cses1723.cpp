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

const int N = 110, M = 1e9+7;
typedef int (*natori)[N];
typedef int akagi[N][N];

akagi adj, x, y;
int n, m, k;

void mul(natori p, natori q, natori res)
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			res[i][j] = 0;
			for (int k=1; k<=n; k++)
			{
				res[i][j] += p[i][k] * q[k][j]%M;
				res[i][j] %= M;
			}
		}
	}
}
natori qpow(natori mat, int k)
{
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	natori res=x, tmp=y;
	rep(i,1,n) res[i][i] = 1;
	for (; k; k>>=1)
	{
		if (k&1)
		{
			mul(res, mat, tmp);
			swap(res, tmp);
		}
		mul(mat, mat, tmp);
		swap(mat, tmp);
	}
	return res;
}
signed main()
{
	cin >> n >> m >> k;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		adj[u][v]++;
	}
	natori res = qpow(adj, k);
	cout << res[1][n] << '\n';	
}
