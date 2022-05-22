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

const int N = 2e5+10;

/*
ans = 0;
dp[0] = 0
ans = max(ans, dp[i]);
dp[i] = max(dp[i-1],0) + a[i];
   */
int n;

signed main(){
	cin >> n;
	int ans=-9e18, dp=0, a;
	rep(i,1,n){
		cin >> a;
		dp = max(dp,0LL) + a;
		ans = max(ans, dp);
	}	
	cout << ans << '\n';
}
