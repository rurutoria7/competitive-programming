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

int n;
vector<pii> a;

signed main(){
	cin >> n;
	rep(i,1,n){
		int m, s, t;
		cin >> m >> s >> t;
		a.pb({s,m});
		a.pb({t,-m});
	}
	sort(a.begin(), a.end(), [](pii x, pii y){
		if (x.ff != y.ff) return x.ff < y.ff;
		return x.ss > y.ss;
	});
	
	int mx=0, nw=0;
	for (auto x: a){
		nw += x.ss;
		mx = max(mx,nw);
	}
	cout << mx << '\n';
}
