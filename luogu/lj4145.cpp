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
#define M ((l+r)/2)
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, m, a[N];

struct Seg
{
	int tr[N<<2];

	void build(int u=1, int l=1, int r=n)
	{
		if (l == r) tr[u] = a[l];
		else
		{
			build(u<<1, l, M);
			build(u<<1|1, M+1, r);
			tr[u] = tr[u<<1] + tr[u<<1|1];
		}
	}

	int query(int ql, int qr, int u=1, int l=1, int r=n)
	{
		if (ql <= l && r <= qr) return tr[u];
		else
		{
			int ans = 0;
			if (ql <= M) ans += query(ql, qr, u<<1, l, M);
			if (qr >  M) ans += query(ql, qr, u<<1|1, M+1, r);
			return ans;
		}
	}
	
	void modify(int ql, int qr, int u=1, int l=1, int r=n)
	{
		if (l == r)
		{
			tr[u] = sqrt(tr[u]);
		}
		else
		{
			if (ql <= M && tr[u<<1] != M-l+1) modify(ql, qr, u<<1, l, M);
			if (qr >  M && tr[u<<1|1] != r-M) modify(ql, qr, u<<1|1, M+1, r);
			tr[u] = tr[u<<1] + tr[u<<1|1];
		}
	}
} seg;


signed main()
{
	roadroller
	cin >> n;
	rep(i,1,n) cin >> a[i];
	seg.build();

	cin >> m;
	while (m--)
	{
		int opr, l, r;
		cin >> opr >> l >> r;
		if (l > r) swap(l, r);
		if (opr == 0) seg.modify(l, r);
		if (opr == 1) cout << seg.query(l, r) << '\n';
	}
}

