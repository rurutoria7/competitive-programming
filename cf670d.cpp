#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, M = 1e9+7;

int n, t, a[N], b[N], c[N];
set<int> sa, sb, sc;

signed main()
{
	mothersrosario
	cin >> t;
	while (t--)
	{
		sa.clear();
		sb.clear();
		sc.clear();
		cin >> n;
		rep(i,1,n) cin >> a[i];
		rep(i,1,n) cin >> b[i];
		rep(i,1,n) cin >> c[i];
		int ans = 1;
		rep(i,1,n)
		{
			if (c[i] == 0)
			{
				int x = 0;
				if (sb.find(a[i]) == sb.end() && sc.find(a[i]) == sc.end()) x++;
				if (sa.find(b[i]) == sa.end() && sc.find(b[i]) == sc.end()) x++;	
				if (a[i] == b[i]) x--;
				ans = ans*x%M;
				sa.insert(a[i]);
				sb.insert(b[i]);
			}
			sc.insert(c[i]);
		}
		cout << ans << '\n';
	}
}
