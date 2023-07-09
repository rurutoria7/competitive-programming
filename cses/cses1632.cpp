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

const int N = 2e5+10;

pii a[N];
int n, k;
multiset<int> s;

signed main()
{
	cin >> n >> k;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	sort(a+1, a+1+n, [](pii x, pii y){
		return x.ss < y.ss;
	});
	rep(i,1,k) s.insert(0);
	int ans = 0;
	rep(i,1,n)
	{
		if (*s.begin() <= a[i].ff)
		{
			auto it = prev(s.upper_bound(a[i].ff));
			s.erase(it);
			s.insert(a[i].ss);
			ans++;
		}
	}
	cout << ans << '\n';
}
