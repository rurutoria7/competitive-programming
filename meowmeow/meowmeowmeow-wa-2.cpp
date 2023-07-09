#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

multiset<int> ed;
int n;
pii a[N];

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	sort(a+1, a+1+n);
	rep(i,1,n)
	{
		if (ed.empty() || a[i].ss < *ed.begin()) ed.insert(a[i].ss);
		else
		{
			auto it = prev(ed.upper_bound(a[i].ss));
			ed.erase(it);
			ed.insert(a[i].ss);
		}
	}
	assert(ed.size() <= 4);
	cout << ed.size() << '\n';
}
