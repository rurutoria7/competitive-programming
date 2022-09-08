#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 210;

int dp[N][N], a[N][N], n, m;

signed main(){
	cin >> m >> n;
	rep(i,1,m)
		rep(j,1,n) cin >> dp[i][j];

	rep(i,1,m)
		rep(j,1,n)
			if (i==1) dp[i][j] += dp[i][j-1]+a[i][j];
			else if (j == 1) dp[i][j] += dp[i-1][j];
			else dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
	cout << dp[m][n] << '\n';
}
