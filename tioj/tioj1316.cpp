#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
sort by ri

rep(i,1,n), adopt i if you can:
    if (query_mx(li,ri) < 2)
        ans++
        add(li,ri,1)
*/

const int N = 4e3+10;

int n, l[N];
vector<pii> a;

struct Seg
{
    int tr[N<<3], tag[N<<3];
    
    void upd(int u, int x) { tr[u] += x, tag[u] += x; }
    void pull(int u) {tr[u] = max(tr[u<<1], tr[u<<1|1]);}
    void push(int u) { upd(u<<1, tag[u]), upd(u<<1|1, tag[u]), tag[u] = 0; }
    void add(int ql, int qr, int u=1, int l=1, int r=n*2) // a[ql,qr]++
    {
        if (qr<l || r<ql) return;
        if (ql<=l && r<=qr) upd(u,1);
        else
        {
            int m = (l+r)>>1;
            push(u);
            add(ql,qr,u<<1,l,m);
            add(ql,qr,u<<1|1,m+1,r);
            pull(u);
        }
    }
    int query(int ql, int qr, int u=1, int l=1, int r=n*2) // max[ql,qr]
    {
        if (qr<l || r<ql) return 0;
        if (ql<=l && r<=qr) return tr[u];
        push(u);
        int m = (l+r)>>1;
        return max(query(ql,qr,u<<1,l,m), query(ql,qr,u<<1|1,m+1,r));
    }
} seg;

signed main()
{
    lyx_my_wife
    cin >> n;
    rep(i,1,2*n)
    {
        int x;
        cin >> x;
        if (l[x]) a.pb({l[x],i});
        else l[x] = i;
    }
    sort(a.begin(), a.end(), [](pii x, pii y){ return x.ss < y.ss; });

    int ans = 0;
    for (auto x: a)
    {
        if (seg.query(x.ff, x.ss) < 2)
        {
            seg.add(x.ff, x.ss);
            ans++;
        }
    }
    cout << ans << '\n';
}
