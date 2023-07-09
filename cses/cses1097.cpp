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
int n, dp[N][N], sum[N];

// dp[i][j]: 先手可以在 [i,j] 取得的最大分數
// dp[i][j] = max(sum[i,j] - dp[i][j-1], sum[i,j] - dp[i+1][j])

signed main()
{
	lyx
	cin >> n;
	rep(i,1,n) cin >> sum[i], sum[i] += sum[i-1];
	
	rep(len,1,n)
	{
		for (int l=1, r=len; r<=n; l++, r++)
		{
			dp[l][r] = sum[r] - sum[l-1] - min(dp[l][r-1], dp[l+1][r]);
		}
	}	
	cout << dp[1][n] << '\n';
}
