#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

struct rec {double u, d, l, r;};
vector<rec> v;

int eq (double x, double y){ return abs(x-y)<1e-5;}
int in (double x, double y, rec r){
	if (eq(x,r.l) || eq(x,r.r) || eq(y,r.u) || eq(y,r.d))
		return 0;
	return (r.l<x && x<r.r) && (r.d<y && y<r.u);
}

signed main(){
	liyuu_my_wife
	char c;
	while (cin >> c, c=='r'){
		double u, d, l, r;
		cin >> l >> u >> r >> d;
		v.pb({u,d,l,r});
	}
	double x, y;
	int cnt = 0;
	while (cin >> x >> y, !eq(x,9999.9)||!eq(y,9999.9)){
		int flag = 0;
		cnt++;
		for (int i=0; i<v.size(); i++){
			if (in(x,y,v[i])){
				cout << "Point " << cnt << " is contained in figure " << i+1 << "\n";
				flag = 1;
			}
		}
		if (!flag) cout << "Point " << cnt << " is not contained in any figure\n";
	}
}
