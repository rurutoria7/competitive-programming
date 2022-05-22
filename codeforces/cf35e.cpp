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

int l[N], r[N], h[N], n;

int val[N<<1], m;
void lsh(){
	for (int i=0; i<n; i++)
		val[m++] = l[i], val[m++] = r[i];
	sort(val,val+m);
	m = unique(val,val+m)-val;
	for (int i=0; i<n; i++){
		l[i] = lower_bound(val,val+m,l[i])-val;
		r[i] = lower_bound(val,val+m,r[i])-val;
	}
	m--;
}

struct Seg{
	int tr[N<<3], lz[N<<3];
	void init(){
		memset(lz,-1,sizeof(lz));
	}
	void upd (int u, int x){
		if (x < 0) return;
		tr[u] = max(tr[u], x);
		lz[u] = max(lz[u], x);
	}
	void push (int u){
		upd(u*2,lz[u]);
		upd(u*2+1,lz[u]);	
		lz[u] = -1;
	}
	void modify (int ql, int qr, int x, int u=1, int l=0, int r=m){
		if (ql<=l && r<=qr){
			upd(u,x);
			return;
		}
		push(u);
		int mid = (l+r)/2;
		if (ql<mid) modify(ql,qr,x,u*2,l,mid);
		if (qr>mid) modify(ql,qr,x,u*2+1,mid,r);
	}
	int query (int i, int u=1, int l=0, int r=m){
		if (r-l == 1) return tr[u];
		int mid = (l+r)/2;
		push(u);
		if (i<mid) return query(i,u*2,l,mid);
		else return query(i,u*2+1,mid,r);
	}
} seg;

signed main(){
	//*
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	// */
	seg.init();
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> h[i] >> l[i] >> r[i];
	lsh();

	for (int i=0; i<n; i++)
		seg.modify(l[i],r[i],h[i]);

	vector<pii> ans;
	for (int i=0; i<=m; i++){
		if (i==0){
			ans.pb({val[i],0});
			ans.pb({val[i],seg.query(i)});
		}
		else if (i == m){
			ans.pb({val[i],seg.query(i-1)});
			ans.pb({val[i],0});
		}
		else{
			int lh = seg.query(i-1);
			int rh = seg.query(i);
			if (lh != rh){
				ans.pb({val[i],lh});
				ans.pb({val[i],rh});
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto x: ans){
		cout << x.ff << ' ' << x.ss << '\n';
	}
}

