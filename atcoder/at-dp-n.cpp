#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 410;

int dp[N][N], n, a[N];

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i], a[i] += a[i-1];
	for (int len=2; len<=n; len++)
	{
		for (int l=1, r=len; r<=n; l++,r++)
		{
			dp[l][r] = 1e18;
			for (int m=l; m<r; m++)
			{
				dp[l][r] = min(dp[l][r], dp[l][m]+dp[m+1][r]);
			}
			dp[l][r] += a[r]-a[l-1];
		}
	}
	cout << dp[1][n] << '\n';
}
