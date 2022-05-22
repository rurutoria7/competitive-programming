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

const int N = 1010, M = 1e9+7;

int n,dp[N][N];
char G[N][N];
/*
dp[i][j] = dp[i-1][j] + dp[i][j-1]
if (G[i][j]) dp[i][j] = 0


   */

signed main(){
	cin >> n;
	rep(i,1,n){
		rep(j,1,n){
			cin >> G[i][j];
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			if (G[i][j] == '*') dp[i][j] = 0;
			else if (i==1 && j==1) dp[1][1] = 1;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
		}
	}		
	cout << dp[n][n] << '\n';
}
