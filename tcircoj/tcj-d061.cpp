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

int n, ql, qr;
set<pii> s;

signed main(){
	cin >> n >> ql >> qr;
	rep(i,1,n){
		int x, y;
		cin >> x >> y;
		s.insert({x,y});
	}
	
	int r1=ql, r2=ql, ans = 0;
	for (auto x: s){
		if (x.ff > r2){
			cout << -1 << '\n';
			return 0;
		}
		if (x.ss <= r2) continue;
		if (r1>=x.ff) ans--;
		else r1=r2;
		r2 = x.ss;
		ans++;
		if (r2 >= qr) break;
	}
	cout << (r2>=qr? ans+1:-1) << '\n';
}
