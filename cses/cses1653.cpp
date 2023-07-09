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

const int N = 22;

// dp[s]: min ride to send s
// ep[s]: to send s in best way, min weight of last ride
// dp[s] = min(dp[s/last]) + 1
// option = {}

int n, w[N], x;
pii dp[(1<<N)];

signed main()
{
	cin >> n >> x;
	rep(i,0,n-1) cin >> w[i];
	for (int i=1; i<(1<<n); i++)
	{
		//de(i), dd
		dp[i] = {1e9, 0};
		for (int j=0; j<n; j++)
		{
			if (!(i&(1<<j))) continue;
			pii src = dp[i^(1<<j)];
			if (src.ss + w[j] <= x)
				src.ss += w[j];	
			else
				src.ff++, src.ss = w[j];
			dp[i] = min(dp[i], src);
		//	de(j), de(src.ff), de(src.ss), dd
		}
		//de(dp[i].ff), de(dp[i].ss), dd
	}
	cout << dp[(1<<n)-1].ff+1 << '\n';
}
