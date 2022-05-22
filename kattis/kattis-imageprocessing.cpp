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

const int N = 50;

int n, m, h, w;
int a[N][N], b[N][N];

int calc (int opr, int opc){
	int res = 0;
	for (int i=opr,ii=n; i<opr+n; i++,ii--){
		for (int j=opc,jj=m; j<opc+m; j++,jj--){
			res += a[i][j]*b[ii][jj];
		}
	}
	return res;
}

signed main(){
	cin >> h >> w >> n >> m;
	rep(i,1,h) rep(j,1,w) cin >> a[i][j];
	rep(i,1,n) rep(j,1,m) cin >> b[i][j];

	rep(i,1,h-n+1){
		rep(j,1,w-m+1){
			cout << calc(i,j) << ' ';
		}
		cout << '\n';
	}
}
