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

/*
dp[i][j]: end with a[i], b[j]

dp[i][j] = max{
	dp[i-1][j-1] + (a[i]==a[j]? 8:-5)
	dp[i][j-1]-3
	dp[i-1][j]-3
}
dp[i][0] = i*-3
dp[0][i] = i*-3
dp[0][0] = 0
   */

const int N = 510;

int dp[N][N], a[N], b[N];

signed main(){
	string x, y;
	cin >> x >> y;
	rep(i,1,x.size()) a[i] = x[i-1];
	rep(i,1,y.size()) b[i] = y[i-1];

	int ans = 0;
	rep(i,0,x.size()){
		rep(j,0,y.size()){
			if (i==0 && j==0) dp[i][j] = 0;
			else if (i==0) dp[i][j] = j*-3;
			else if (j==0) dp[i][j] = i*-3;
			else
				dp[i][j] = max(
					dp[i-1][j-1] + (a[i]==b[j]? 8:-5),
					max(
						dp[i][j-1]-3,
						dp[i-1][j]-3
					)
				);
			dp[i][j] = max(dp[i][j], 0LL);
			ans = max(ans, dp[i][j]);						
		}
	}	
	cout << ans << '\n';
}
