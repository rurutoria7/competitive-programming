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

const int N = 5010;

string a, b;
int dp[N][N], n, m;

signed main()
{
	cin >> a >> b;
	n = a.size(), m = b.size();
	a = " " + a, b = " " + b;

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if (i == 0 || j == 0)
			{
				if (i == 0 && j == 0) dp[i][j] = 0;
				else if (i == 0) dp[i][j] = dp[i][j-1] + 1;
				else if (j == 0) dp[i][j] = dp[i-1][j] + 1;
				continue;	
			}
			dp[i][j] = 9e18;	
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, min(dp[i-1][j-1]+1, dp[i][j-1]+1)));
		}
	}
	cout << dp[n][m] << '\n';
}
