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

const int N = 510, X = N*N/2, M = 1e9+7;

int dp[N][X], n;

int qpow (int i, int j){
	int ans = 1;
	for (; j; j>>=1, i=i*i%M)
		if (j&1) ans = ans*i%M;
	return ans;
}

signed main(){
	cin >> n;
	if (n*(n+1)%4){
		cout << 0 << '\n';
		return 0;
	}
	// dp[i][j] = dp[i-1][j-i] || dp[i-1][j]
	// dp[0][0] = 1
	dp[0][0] = 1;
	rep(i,1,n){
		rep(j,0,X-1){
			dp[i][j] = dp[i-1][j];
			if (j >= i){
				dp[i][j] = (dp[i][j] + dp[i-1][j-i])%M;
			}
		}
	}
	cout << dp[n][n*(n+1)/4]*qpow(2,M-2)%M << '\n';
}
