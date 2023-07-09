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
const int M = 1e9+7;

int inv2 = (M + 1) / 2, n, ans = 0;
signed main()
{
	lyx;
	cin >> n;
	for (int l=1, r=0; l<=n; l=r+1)
	{
		r = n / (n / l);
		int ouo = (n/l)%M;
		int ovo = (l+r)%M;
		int owo = (r-l+1)%M;
		ans = (ans+ouo*ovo%M*owo%M*inv2%M)%M;
	}
	cout << ans << '\n';
}
