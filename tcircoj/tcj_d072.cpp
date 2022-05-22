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

pii a[N];
int n, dp[N][2];

signed main(){
	cin >> n >> a[0].ff, a[0].ss = a[0].ff;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	rep(i,1,n){
		dp[i][0] = min(dp[i-1][0]+abs(a[i].ff-a[i-1].ff),
						dp[i-1][1]+abs(a[i].ff-a[i-1].ss));
		dp[i][1] = min(dp[i-1][0]+abs(a[i].ss-a[i-1].ff),
					dp[i-1][1]+abs(a[i].ss-a[i-1].ss));
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
}
