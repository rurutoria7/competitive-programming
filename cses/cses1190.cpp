#include <bits/stdc++.h>
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

struct Node
{
	long long pre, suf, ans, sum;
	Node () { pre = suf = ans = sum = 0; }
	Node (long long x)
	{
		pre = suf = ans = (x>0)*x;
		sum = x;	
	}
};

Node operator * (Node ln, Node rn)
{
	Node res(0);
	res.pre = max(ln.pre, ln.sum + rn.pre);
	res.suf = max(rn.suf, rn.sum + ln.suf);
	res.ans = max(max(max(max(ln.suf + rn.pre, res.pre), res.suf), ln.ans), rn.ans);
	res.sum = ln.sum + rn.sum;
	return res;
}
struct segtree
{
	Node tr[N<<1];
	int n;
	void modify(int p, int x)
	{
		p--;
		for (tr[p+=n] = Node(x); p>1; p>>=1)
		{
			if (p&1) tr[p>>1] = tr[p^1] * tr[p];
			else tr[p>>1] = tr[p] * tr[p^1];
		}
	}
	long long query(int l, int r)
	{
		l--;
		Node lans(0), rans(0);
		for (l+=n, r+=n; l<r; l>>=1, r>>=1)
		{
			if (l&1) lans = lans * tr[l++];
			if (r&1) rans = tr[--r] * rans;
		}
		return (lans * rans).ans;
	}
	void init(int _n)
	{
		n = _n;
		for (int i=0,x; i<n; i++) cin >> x, tr[i+n] = Node(x);
		for (int i=n-1; i>0; i--) tr[i] = tr[i<<1] * tr[i<<1|1];
	}
} sgt;

int n, m;

signed main()
{
	roadroller
	cin >> n >> m;
	sgt.init(n);	
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		sgt.modify(x, y);
		cout << sgt.query(1,n) << '\n';
	}
}
