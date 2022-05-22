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

const int N = 210;

int a[N][N], n, m, dp[N];

signed main(){
	cin >> m >> n;
	rep(i,1,m)
		rep(j,1,n)
			cin >> a[i][j];
	rep(i,1,m)
		rep(j,1,n)
			a[i][j] += a[i-1][j];
	int ans = 0;
	rep(i,1,m)
		rep(j,i,m)
			rep(k,1,n)
				dp[k] = max(dp[k-1],0LL) + a[j][k]-a[i-1][k], ans = max(ans, dp[k]);
	cout << ans << '\n';
}
