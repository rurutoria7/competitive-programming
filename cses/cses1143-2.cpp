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

const int N = 2e5+10;

set<pii> s;
int n, m, a[N];

signed main()
{
	roadroller
	cin >> n >> m;
	rep(i,1,n)
	{
		int x;
		cin >> x;
		s.insert({x, i});
	}

	rep(i,1,m)
	{
		int q;
		cin >> q;
		auto lwb = s.lower_bound({q, 0});
		if (lwb == s.end()) cout << 0 << '\n';
		else
		{
			cout << lwb->ss << '\n';
			pii ouo = *lwb;
			ouo.ff -= q;
			s.erase(lwb);
			s.insert(ouo);
		}
	}	

}
