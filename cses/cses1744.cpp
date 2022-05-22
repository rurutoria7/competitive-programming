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
dp[i][j]: width = i, height = j, min cost
dp[i][j] = min{
	1. cut vertical
		dp[1][j]+dp[i-1][j], dp[2][j]+dp[i-2][j], ..., dp[i-1][j]+dp[1][j]
	2. cut horizontal
   		dp[i][1]+dp[i][j-1], dp[i][k]+dp[i][j-k], 1<=k<=(j/2)
   */
const int N = 510;

int dp[N][N], n, m;

signed main(){
	cin >> n >> m;
	if (n > m) swap(n,m);
	rep(i,2,m){
		rep(j,i,m){
			if (i == j) dp[i][j] = 0;
			else{
				dp[i][j] = 9e18;
				rep(k,1,(i/2)){
					dp[i][j] = min(dp[i][j],
							dp[min(i-k,j)][max(i-k,j)]+dp[min(k,j)][max(k,j)]+1);
				}
				rep(k,1,(j/2)){
					dp[i][j] = min(dp[i][j],
							dp[min(i,j-k)][max(i,j-k)]+dp[min(k,i)][max(k,i)]+1);
				}
			}
		}
	}
	cout << dp[n][m] << '\n';
}
