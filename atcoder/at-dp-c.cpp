#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int a[N][5], n, dp[N][5]; 

// dp[i][j]: 1~i, end with j, max weight
// dp[i][j] = max(dp[i-1][x] + a[i][x])

signed main()
{
	cin >> n;
	rep(i,1,n)
		rep(j,1,3)
			cin >> a[i][j];	
	rep(i,1,n)
	{
		dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a[i][1];
		dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + a[i][2];
		dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + a[i][3];
	}
	cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << '\n';
}
