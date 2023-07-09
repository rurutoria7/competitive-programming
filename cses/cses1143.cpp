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

// bs(x): first position bs(x) s.t. max(1..bs(x)) > x
// for x in r:
//		i = bs(x)
// 		seg.decrease(i, x)

struct segtree {
    long long tr[N<<1], tag[N], n;
   void modify(int p, int x) {
		p--;
        for(tr[p+=n] -= x; p > 1; p>>=1)
            tr[p>>1] = max(tr[p],tr[p^1]);
    }
    long long query(int l,int r) { // [l,r]
		l--;
        long long res = 0;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if(l&1) res = max(res, tr[l++]);
            if(r&1) res = max(res, tr[--r]);
        }
        return res;
    }
    void init(long long v[],int _n) {
        n = _n;
        for(int i = 0; i < n; i++) tr[i+n] = v[i];
        for(int i = n-1; i > 0; i--) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }
} sgt;

int n, m, h[N], r[N];

int bs(int x)
{
	int i = 0, len = n;
	if (sgt.query(1,n) < x) return 0;
	while (len > 0)
	{
		if (sgt.query(1,i+len) >= x)
			len >>= 1;
		else
			i += len;
	}
	return i+1;
}

signed main()
{
	roadroller
	cin >> n >> m;
	rep(i,1,n) cin >> h[i];
	rep(i,1,m) cin >> r[i];
	sgt.init(h+1, n);
	rep(i,1,m)
	{
		int liv = bs(r[i]);
		if (liv) sgt.modify(liv, r[i]);
		cout << liv << ' ';
	}
}
