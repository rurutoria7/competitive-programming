#include <bits/stdc++.h>
#define cmax(a,b) a = max(a,b)
#define cmin(a,b) a = min(a,b)
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

/*
dp[i][j]: number i~j, first player can get max
dp[i][j] = max(sum[i][j]-dp[i][j-1], sum[i][j]-dp[i+1][j-1])
dp[i+1][j] = 0
*/

const int N = 5010;

int n, a[N];
int dp[N][N], sum[N];

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) sum[i] = sum[i-1]+a[i];

	for (int len=1; len<=n; len++)
	{
		for (int l=1,r=len; r<=n; l++,r++)
		{
			int s = sum[r]-sum[l-1];
			dp[l][r] = max(s-dp[l][r-1], s-dp[l+1][r]);
		}
	}
	cout << dp[1][n] << '\n';
}
