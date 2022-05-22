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

if all number in 1~n 

if only query 1~n
binary search on seg

if query 1~1, 1~2, 1~3, ..., 1~n
for every search add a number

if query l floating
for every element in segment tree -= seg(lth segment)

st[i] version j: cnt of i in [1,j]
*/
const int N = 2e5+10;

int n, m, a[N];

struct Seg{
	int root[N<<6], ptr;
	int sum[N<<6], lc[N<<6], rc[N<<6];
	
	int build (int l, int r){
		int rt = ++ptr;
		if (l<r){
			int m = (l+r)/2;
			lc[rt] = build(l,m);
			rc[rt] = build(m+1,r);
		}
		return rt;
	}
	//creat new chain will be modify, return the new chain root;
	int modify (int old, int l, int r, int q){
		int rt = ++ptr;
		if (q<l || q>r) return old;
		if (l==r){
			sum[rt] = sum[old]+1;
			return rt;
		}
		int m = (l+r)/2;
		lc[rt] = modify(lc[old],l,m,q);
		rc[rt] = modify(rc[old],m+1,r,q);
		sum[rt] = sum[lc[rt]] + sum[rc[rt]];
		return rt;
	}
	//return the kth one in l~r on tree of version2 - version1
	int query (int v1, int v2, int l, int r, int k){
		int m = (l+r)/2;
		if (l==r) return l;
		if (sum[lc[v2]]-sum[lc[v1]] >= k){
			return query(lc[v1],lc[v2],l,m,k);
		}
		return query(rc[v1],rc[v2],m+1,r,k-sum[lc[v2]]+sum[lc[v1]]);
	}
} seg;

int ord[N], val[N];
void lsh (){
	rep(i,1,n) val[i] = a[i];
	sort(val+1,val+1+n);
	int x = unique(val+1,val+1+n)-val-1;
	rep(i,1,n) ord[i] = lower_bound(val+1,val+1+x,a[i])-val;
}

signed main(){
	minamisan
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	lsh();
	seg.root[0] = seg.build(1,n);
	rep(i,1,n){
		seg.root[i] = seg.modify(seg.root[i-1],1,n,ord[i]);
	}	
	rep(i,1,m){
		int l, r, k;
		cin >> l >> r >> k;
		cout << val[seg.query(seg.root[l-1],seg.root[r],1,n,k)] << '\n';
	}
}