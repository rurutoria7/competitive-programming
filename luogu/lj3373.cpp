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
/*
sub_v = sub_v*x + y
*/

int n, m, p, a[N];

struct Seg{
	int v[N<<2], atag[N<<2], mtag[N<<2], sz[N<<2];
	void upd (int u, int mul, int add){
		v[u] = (v[u]*mul%p + add*sz[u])%p;
		mtag[u] = mtag[u]*mul%p;
		atag[u] = (atag[u]*mul%p+add)%p;
	}
	void pull (int u){
		v[u] = (v[u<<1]+v[u<<1|1])%p;
	}
	void push (int u){
		upd(u<<1,mtag[u], atag[u]);
		upd(u<<1|1,mtag[u],atag[u]);
		mtag[u] = 1;
		atag[u] = 0;
	}
	void build (int u=1, int l=1, int r=n){
		mtag[u] = 1;
		if (l==r){
			v[u] = a[l];
			sz[u] = 1;
		}
		else{
			int m = (l+r)/2;
			build(u<<1,l,m);
			build(u<<1|1,m+1,r);
			pull(u);
			sz[u] = sz[u<<1]+sz[u<<1|1];
		}
	}
	void modify (int ql, int qr, int mul, int add, int u=1, int l=1, int r=n){ //opr==0, +k, opr==1, *k
		//de(ql), de(qr), de(mul), de(add), de(u), de(l), de(r), dd;
		if (qr<l || r<ql) return;
		if (ql<=l && r<=qr){
			upd(u,mul,add);
			return;
		}
		int m = (l+r)/2;
		push(u);
		modify(ql,qr,mul,add,u<<1,l,m);
		modify(ql,qr,mul,add,u<<1|1,m+1,r);
		pull(u);
	}
	int query (int ql, int qr, int u=1, int l=1, int r=n){
		if (qr<l || r<ql) return 0;
		if (ql<=l && r<=qr){
			return v[u];
		}
		int m = (l+r)/2;
		push(u);
		return (query(ql,qr,u<<1,l,m)+query(ql,qr,u<<1|1,m+1,r))%p;
	}
} seg;

signed main(){
	minamisan
	cin >> n >> m >> p;
	rep(i,1,n) cin >> a[i];
	seg.build();
	rep(i,1,m){
		int o, x, y, k;
		cin >> o >> x >> y;
		if (o == 1){
			cin >> k;
			seg.modify(x,y,k,0);
		}
		if (o == 2){
			cin >> k;
			seg.modify(x,y,1,k);
		}
		if (o == 3){
			cout << seg.query(x,y) << '\n';
		}
	}
}