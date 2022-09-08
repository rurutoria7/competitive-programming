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

int a[N], n, dp[N];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];

	dp[1] = a[1];
	rep(i,2,n){
		dp[i] = min(dp[i-1], dp[i-2])+a[i];
	}
	cout << dp[n] << '\n';
}
