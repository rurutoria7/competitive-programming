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

const int N = 510;

int n;
pii a[N];
int dp[N][N];

signed main(){
	cin >> n >> a[1].ff;
	rep(i,1,n) cin >> a[i].ss, a[i+1].ff = a[i].ss;

	for (int len=1; len<=n; len++){
		for (int l=1,r=len; r<=n; l++,r++){
			if (l==r){
				dp[l][r] = 0;
				continue;
			}
			dp[l][r] = 9e18;
			for (int i=l; i<r; i++){
				dp[l][r] = min(
					dp[l][r],
					dp[l][i]+dp[i+1][r]+a[l].ff*a[i].ss*a[r].ss
				);
			}	
		}
	}
	cout << dp[1][n] << '\n';
}
