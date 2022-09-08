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

const int N = 1e5+10;

int n, a[N];
multiset<pii> s;

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i], s.insert({a[i],i});

	int ans = 0;
	rep(i,1,n){
		for (auto it=prev(s.end()); it->ss<i; it--,s.erase(next(it)));
		if (s.size())
			ans = max(ans, s.rbegin()->ff-a[i]);
	}
	cout << ans << '\n';
}
