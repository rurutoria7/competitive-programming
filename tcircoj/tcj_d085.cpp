#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+1, K = 101;

int n, k, src[2][K], dp[2][K], p[N];

signed main(){
	cin >> n >> k;
	rep(i,1,n) cin >> p[i];
	for (int i=1; i<=n; i++){
		for (int j=0; j<=k; j++){
			if (i == 1){
				dp[i&1][j] = 0;
				src[i&1][j] = -p[i];
			}
			else if (j == 0){
				dp[i&1][j] = dp[i&1^1][j];
				src[i&1][j] = max(-p[i],src[i&1^1][j]);
			}
			else{
				dp[i&1][j] = max(dp[i&1^1][j],p[i]+src[i&1^1][j-1]);
				src[i&1][j] = max(src[i&1^1][j],dp[i&1^1][j]-p[i]);
			}
		}
	}
	cout << dp[n&1][k] << '\n';
}
