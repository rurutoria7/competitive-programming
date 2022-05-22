#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define las(x) (prev(x.end()))
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, q, a[N], sum[N];

signed main()
{
	liyuu_my_wife
	cin >> n >> q;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) sum[i] = sum[i-1]+a[i];
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << sum[r]-sum[l-1] << '\n';
	}
}
