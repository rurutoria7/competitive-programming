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
dp[i][j] = 1~i, i+1 is j, all possibility
dp[i][j] = 
dp[i-1][a[i]]
a[i] == 0
(j+1 available)*dp[i-1][j+1] + 
(j available)*dp[i-1][j+1] + 
(j-1 available)*dp[i-1][j+1]

dp[i][j] = 1~i, a[i] == j, all posibility
dp[i][j] = 
if a[i-1] == 0
	dp[i][j] = dp[i-1][j+1] + dp[i-1][j] + dp[i-1][j-1]
else
	dp[i][j] = legal(i-1,i)*(dp[i-1][a[i-1]])
dp[1][j] = 1
ans = dp[n][1~m]
   */

const int N = 1e5+10, M = 110, P = 1e9+7;

int a[N], n, m, dp[N][M];

signed main(){
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	
	if (a[1] == 0){
		rep(i,1,m) dp[1][i] = 1;
	}	
	else{
		dp[1][a[1]] = 1;
	}

	rep(i,2,n){
		rep(j,1,m){
			if (a[i-1] == 0){
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%P;
			}
			else{
				dp[i][j] = (abs(j-a[i-1])<=1)*(dp[i-1][a[i-1]])%P;
			}
		}
	}
	int ans = 0;
	if (a[n] == 0)	
		rep(i,1,m) ans = (ans+dp[n][i])%P;
	else
		ans = dp[n][a[n]];
	cout << ans << '\n';
}
