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
pii a[N];

int cmp (pii x, pii y){
	return x.ff*y.ss < y.ff*x.ss;
}

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i].ff;
	rep(i,1,n) cin >> a[i].ss;
	sort(a+1,a+1+n,cmp);
	
	int x=0, y=0;
	rep(i,1,n){
		y += x*a[i].ss;
		x += a[i].ff;
	}
	cout << y << '\n';
}
