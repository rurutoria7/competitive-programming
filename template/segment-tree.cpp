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

const int N = 1e5+10;

struct Tag
{
    int add = 0;
    Tag()
    {
        add = 0;
    }
    void operator += (const Tag &tg)
    {
        add += tg.add;
    }
};

struct Data
{
    int sum = 0, len = 0;
    Data()
    {
        sum = 0;
        len = 0;
    }
    Data operator + (const Data &j)
    {
        return Data(sum+j.sum, len+j.len);
    }
    void operator += (const Tag &tg)
    {
        sum += len*tg.add;
    }
};

template <class D, class T>
struct Seg 
{
    int L, R;
    D tr[N<<2];
    T tag[N];
    
    void upd(int u, T x)
    {
        tr[u] += x;
        tag[u] += x;
    }
    void build(D *begin, D *end, int u=1) // build from an array of size n
    {
        tag[u] = Tag();
        if (begin == end) tr[u] = *begin;
        else
        {
            D *m = begin + (end-begin)/2;
            build(begin, m, u<<1);
            build(m+1, end, u<<1|1);
            tr[u] = tr[u<<1] + tr[u<<1|1];
        }
    }
    void modify(int ql, int qr, T x, int u, int l, int r)
    {
        if (ql <= l && r <= qr) upd(u,x);
        else
        {
            upd(u<<1,tag[u]), upd(u<<1|1,tag[u]), tag[u].clear();
            int m = (l + r) >> 1;
            if (ql <= m) modify(ql, qr, x, u<<1, l, m);
            if (m < qr) modify(ql, qr, x, u<<1|1, m+1, r);
            tr[u] = tr[u<<1] + tr[u<<1|1];
        }
    }
    D query(int ql, int qr, int u, int l, int r)
    {
        if (ql <= l && r <= qr) return tr[u];
        upd(u<<1,tag[u]), upd(u<<1|1,tag[u]), tag[u].clear();
        int m = (l+r) >> 1;
        D res;
        if (ql <= m) res = res + query(ql, qr, u<<1, l, m);
        if (m < qr) res = res + query(ql, qr, u<<1|1, m+1, r);
        return res;
    }

    void modify(int ql, int qr, T x){ modify(ql, qr, x, 1, L, R); }
    D query(int ql, int qr){ return query(ql, qr, 1, L, R); }
};

int n, m;
Data a[N];

signed main()
{
    //lyx_my_wife
    cin >> n >> m;
    rep(i,1,n) cin >> a[i].sum, a[i].len = 1;

    Seg<Data,Tag> seg = {1,n};
    seg.build(a+1,a+1+n);

    while(m--)
    {
        int opr, x, y, z;
        cin >> opr;
        if (opr == 1)
        {
            cin >> x >> y >> z;
            seg.modify(x,y,{z});
        }
        else
        {
            cin >> x >> y;
            cout << seg.query(x,y).sum << '\n';
        }
    }
}