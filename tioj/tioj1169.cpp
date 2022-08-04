#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cerr << #x << "=" << x << ", "
#define dd cerr << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, q, c, colo[N];

struct Ans { int len, pf, sf, ans; };
inline Ans operator + (Ans const &lnode, Ans const &rnode)
{
    return
    {
        lnode.len + rnode.len, 
        lnode.pf + (lnode.len == lnode.pf)*rnode.pf, 
        rnode.sf + (rnode.len == rnode.sf)*lnode.sf, 
        max(lnode.sf + rnode.pf, max(lnode.ans, rnode.ans))
    };
}

struct Seg 
{
    int lc[N<<7], rc[N<<7], pcnt;
    Ans val[N<<7];

    int new_node(int len = n)
    {
        val[++pcnt] = {len, len, len, len};
        return pcnt;
    }

    void add(int p, int x, int u, int l=1, int r=n) // x==1, add else rem
    {
        if (l == r)
        {
            if (x == 1) val[u] = {1,0,0,0};
            else val[u] = {1,1,1,1};
        }
        else
        {
            int m = (l+r)/2;
            if (!lc[u]) lc[u] = new_node(m-l+1);
            if (!rc[u]) rc[u] = new_node(r-m);
            if (p <= m) add(p,x,lc[u],l,m);
            else add(p,x,rc[u],m+1,r);
            val[u] = val[lc[u]] + val[rc[u]];
        }
    }

    Ans query(int ql, int qr, int u, int l=1, int r=n)
    {
        if (ql <= l && r <= qr) return val[u];

        int m = (l+r)/2;
        if (!lc[u]) lc[u] = new_node(m-l+1);
        if (!rc[u]) rc[u] = new_node(r-m);

        Ans res = {0,0,0,0};
        if (ql <= m) res = res + query(ql,qr,lc[u],l,m);
        if (m < qr)  res = res + query(ql,qr,rc[u],m+1,r);
        return res;
    }
} seg;

map<int,int> rt;
int get_rt (int x)
{
    if (rt.find(x) == rt.end()) rt[x] = seg.new_node(); 
    return rt[x];
}

signed main()
{
    lyx_my_wife
    cin >> n >> q >> c;
    rep(i,1,n) cin >> colo[i];
    rep(i,1,n) seg.add(i,1,get_rt(colo[i]));
    rep(i,1,q)
    {
        int opr, x, y, z;
        cin >> opr;
        if (opr == 0)
        {
            cin >> x >> y, x++;
            seg.add(x,0,get_rt(colo[x]));
            seg.add(x,1,get_rt(y));
            colo[x] = y;
        }
        else
        { 
            cin >> x >> y >> z, x++;
            cout << seg.query(x,y,get_rt(z)).ans << '\n';
        }
    }
}