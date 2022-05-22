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

const int N = 6e4+10;
const double EPS = 1e-7;

double x[N], v[N], n;

int check (double t){
	double cl=-9e18,cr=9e18;
	rep(i,1,n){
		double nl = x[i]-v[i]*t;
		double nr = x[i]+v[i]*t;
		cl = max(cl,nl);
		cr = min(cr,nr);
		if (cl > cr) return 0;
	}
	return 1;
}

double bs(){
	double i=0, s=1e9;
	if (check(i)) return 0;
	while (s > EPS){
		if (check(i+s)) s/=2;
		else i += s;
	}
	return i+EPS;
}

signed main(){
	cin >> n;
	rep(i,1,n) cin >> x[i];
	rep(i,1,n) cin >> v[i];
	cout << fixed << setprecision(8) << bs() << '\n';
}
