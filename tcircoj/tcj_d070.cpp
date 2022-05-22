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

int dp[N][N];

signed main(){
	string a, b;
	cin >> a >> b;
	rep(i,1,a.size()){
		rep(j,1,b.size()){
			if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[a.size()][b.size()] << '\n';
}
