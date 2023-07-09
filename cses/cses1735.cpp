#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;
// tset=0, tadd=0
// set to x: tset = x, tadd = 0, tr += x * len
// add x: tset do not change, tadd += x, tr = x * len
// set_to(ori, tset) + tadd

int n, q, a[N];

#define M ((l+r)/2)
struct segtree
{
	int tr[N<<2], tset[N<<2], tadd[N<<2], len[N<<2];
	void upd(int u, int ts, int ta)
	{
		if (ts) tset[u] = ts, tadd[u] = ta, tr[u] = (ts+ta) * len[u];
		else tadd[u] += ta, tr[u] += ta * len[u];
	}
	void push(int u)
	{
		upd(u<<1, tset[u], tadd[u]);
		upd(u<<1|1, tset[u], tadd[u]);
		tset[u] = tadd[u] = 0;
	}
	void pull(int u)
	{
		push(u);
		assert(tset[u] == 0);
		assert(tadd[u] == 0);
		tr[u] = tr[u<<1] + tr[u<<1|1];
	}
	void build(int a[], int l=1, int r=n, int u=1)
	{
		len[u] = r-l+1;
		if (l == r) tr[u] = a[l];
		else build(a, l, M, u<<1), build(a, M+1, r, u<<1|1), pull(u);		
	}
	void modify(int ql, int qr, int ts, int ta, int u=1, int l=1, int r=n)
	{
		if (ql<=l && r<=qr) upd(u, ts, ta);
		else
		{
			push(u);
			if (ql <= M) modify(ql, qr, ts, ta, u<<1, l, M);
			if (qr > M) modify(ql, qr, ts, ta, u<<1|1, M+1, r);
			pull(u);
		}	
	}
	int query(int ql, int qr, int u=1, int l=1, int r=n)
	{
		if (ql<=l && r<=qr) return tr[u];
		else
		{
			int sum = 0;
			push(u);
			if (ql <= M) sum += query(ql, qr, u<<1, l, M);
			if (qr > M) sum += query(ql, qr, u<<1|1, M+1, r);
			return sum;
		}
	}
} sgt;
#undef M

signed main()
{
	roadroller
	cin >> n >> q;
	rep(i,1,n) cin >> a[i];
	sgt.build(a);
	//sgt.debug();
	
	while (q--)
	{
		int opr, x, y, z;
		cin >> opr;
		if (opr == 1)
		{
			cin >> x >> y >> z;
			sgt.modify(x,y,0,z);
		}
		if (opr == 2)
		{
			cin >> x >> y >> z;
			sgt.modify(x,y,z,0);
		}
		if (opr == 3)
		{
			cin >> x >> y;
			cout << sgt.query(x,y) << '\n';	
		}
		//sgt.debug();
	}
}

