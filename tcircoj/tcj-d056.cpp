#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n;
set<pii> l;
pii a[N];

signed main(){
	minamisan
	cin >> n;
	rep(i,1,n) cin >> a[i].ss >> a[i].ff;
	sort(a+1,a+1+n,[](pii i, pii j){
		if (i.ss != j.ss) return i.ss < j.ss;
		return i.ff < j.ff;
	});

	int d = 9e18;
	rep(i,1,n){
		pii p = a[i];
		int upb = p.ff+d;
		int lwb = p.ff-d;
		auto uit = l.lower_bound({upb,-9e18});
		auto lit = l.upper_bound({lwb,-9e18});
		for (auto it=lit; it!=uit;){
			d = min(d,abs(p.ss-it->ss)+abs(p.ff-it->ff));
			if (p.ss-it->ss >= d) it = l.erase(it);
			else it++;
		}
		l.insert(p);
	}
	cout << d << '\n';
}