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

const int N = 110, X = 1e5+10;

int n, a[N], dp[N][X];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];
	//dp[i][j] = dp[i-1][j-x[i]] + dp[i-1][j]
	//dp[0][0] = 1
	dp[0][0] = 1;
	rep(i,1,n){
		rep(j,0,X-1){
			if (j >= a[i]){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
			}		
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	vector<int> ans;
	for (int i=1; i<X; i++){
		if (dp[n][i]) ans.pb(i);
	}	
	cout << ans.size() << '\n';
	for (auto x: ans) cout << x << ' ';
	cout << '\n';
}
