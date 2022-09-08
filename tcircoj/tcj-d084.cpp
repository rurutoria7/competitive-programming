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

int n, k, dp[N];//dp[i]: max weight solution that last day is before i
int w[N];
signed main(){
	cin>> n >> k;
	rep(i,1,n) cin >> w[i];
	rep(i,1,n){
		dp[i] = max(dp[i-1], dp[max(0LL,i-k-1)]+w[i]);
	}
	cout << dp[n] << '\n';
}
