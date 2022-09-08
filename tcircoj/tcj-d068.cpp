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

const int N = 1e5+10;

int n, c[N], dp[N];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> c[i];
	if (n==1){
		cout << c[1] << '\n';
		return 0;
	}	
	dp[1]=c[1], dp[2]=c[2];
	rep(i,3,n){
		dp[i] = 1e18;
		if (i>1) dp[i] = min(dp[i], dp[i-1]);
		if (i>2) dp[i] = min(dp[i], dp[i-2]);
		if (i>3) dp[i] = min(dp[i], dp[i-3]);
		dp[i] += c[i];
		//de(i), de(dp[i]), dd;
	}	
	cout << min(dp[n],dp[n-1]) << '\n';
}
