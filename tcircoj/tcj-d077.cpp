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

/*
dp[i]: min cost solution with i must be build
dp[i] = min(dp[i-2k-1]..dp[i-1])+c[i]
dp[1]~dp[k+1] = c[i]
   */
const int N = 2e5+10;

int n, w[N], k;

struct Seg{
	int val[N<<2];
	void modify (int i, int x, int u=1, int l=1, int r=n){
		if (i<l || i>r) return;
		if (l==r){
			val[u] = x;
			return;
		}
		int m = (l+r)/2;
		modify(i,x,u*2,l,m);
		modify(i,x,u*2+1,m+1,r);
		val[u] = min(val[u*2], val[u*2+1]);
	}
	int query (int ql, int qr, int u=1, int l=1, int r=n){
		if (qr<l || r<ql) return 9e18;
		if (ql<=l && r<=qr){
			return val[u];
		}
		int m = (l+r)/2;
		return min(query(ql,qr,u*2,l,m), query(ql,qr,u*2+1,m+1,r));
	}
} seg;
signed main(){
	minamisan
	cin >> n >> k;
	rep(i,1,n) cin >> w[i];
	rep(i,1,k+1) seg.modify(i,w[i]);
	rep(i,k+2,n) seg.modify(i,seg.query(max(1LL,i-2*k-1),i-1)+w[i]);
	cout << seg.query(n-k,n) << '\n';
}
