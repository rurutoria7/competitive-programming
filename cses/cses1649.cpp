#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int N = 2e5+10;

struct segtree {
    long long tr[N<<1], n;
    void modify(int p, int x) {
        for(tr[p+=n] = x; p > 1; p>>=1)
            tr[p>>1] = min(tr[p],tr[p^1]);
    }
    long long query(int l,int r) { // [l,r)
        long long res = 9e18;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if(l&1) res = min(res, tr[l++]);
            if(r&1) res = min(res, tr[--r]);
        }
        return res;
    }
    void init(long long v[],int _n) {
        n = _n;
        for(int i = 0; i < n; i++) tr[i+n] = v[i];
        for(int i = n-1; i > 0; i--) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }
} sgt;

int a[N], n, k;

signed main()
{
	roadroller
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	sgt.init(a+1, n);
	while (k--)
	{
		int opr, x, y;
		cin >> opr >> x >> y;
		if (opr == 1) sgt.modify(x-1, y);
		if (opr == 2) cout << sgt.query(x-1,y) << '\n';
	}
}
