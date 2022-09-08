#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, a[N], b[N], q;

struct Seg1
{
    int sum[N<<2];

    void setto (int p, int x, int u=1, int l=1, int r=n) // range add
    {
        if (l==p && p==r) sum[u] = x;
        else
        {
            int m = (l+r)/2;
            if (p<=m) setto(p, x, u<<1, l, m);
            else setto(p, x, u<<1|1, m+1, r);
            sum[u] = sum[u<<1] + sum[u<<1|1];
        }
    }
    int bs (int x) // max i s.t. a[1]+...+a[i] <= x
    {
        if (sum[1] <= x) return n;
        int u=1, l=1, r=n, s = 0;
        while (l<r)
        {
           // de(u), de(sum[u]), de(l), de(r), de(s), dd
            int m = (l+r)/2;
            if (s+sum[u<<1] <= x)
            {
                s += sum[u*2];
                u = u*2+1;
                l = m+1;
            }
            else
            {
                u = u*2;
                r = m;
            }
        }
      //              de(u), de(l), de(r), de(s), dd

        return r-1;
    }
    int query (int ql, int qr, int u=1, int l=1, int r=n)
    {
        if (ql <= l && r <= qr) return sum[u];
        else
        {
            int m = (l+r)/2;
            int ans = 0;
            if (ql <= m) ans += query(ql, qr, u*2, l, m);
            if (qr > m) ans += query(ql, qr, u*2+1, m+1, r);
            return ans;
        }
    }
} st1, st3;

struct Seg2
{
    int mn[N<<2], tag[N<<2];

    void upd (int u, int x) // plus!!!
    {
        mn[u] += x;
        tag[u] += x;
    }
    void push(int u)
    {
        upd(u<<1, tag[u]);
        upd(u<<1|1, tag[u]);
        tag[u] = 0;
    }
    void pull (int u)
    {
        mn[u] = min(mn[u<<1], mn[u<<1|1]);
    }
    void add (int ql, int qr, int x, int u=1, int l=1, int r=n) // range add x
    {
        if (ql <= l && r <= qr) upd(u, x);
        else
        {
            push(u);
            int m = (l+r)/2;
            if (ql <= m) add(ql, qr, x, u*2, l, m);
            if (qr > m) add(ql, qr, x, u*2+1, m+1, r);
            pull(u);
        }
    }
    int bs (int x) // min i s.t. min(1...i) < x
    {
        if (mn[1] >= x) return 0;
        int u=1, l=1, r=n, mnn = 9e18;
        while (l<r)
        {
            push(u);
            int m = (l+r)/2;
            if (min(mnn, mn[u*2]) >= x)
            {
                mnn = min(mnn, mn[u*2]);
                u = u*2+1;
                l = m+1;
            }
            else
            {
                u = u*2;
                r = m;
            }
        }
        return l;
    }
} st2;

void change(int aa, int bb, int i, int kill = 0)
{
    if (kill)
    {
        st3.setto(i,1);
    }
    else
    {
        st3.setto(i,0);
    }
    st1.setto(i, aa);
    st2.add(i, n, aa - a[i]);
    st2.add(i, i, bb - b[i]);
    a[i] = aa, b[i] = bb;
}


signed main()
{
    lyx
    cin >> n;
    rep(i,1,n)
    {
        int x, y;
        cin >> x >> y;
        change(x, y, i);
    }

    cin >> q;
    while (q--)
    {
        int opr, x, y, z;
        cin >> opr;

        if (opr == 1)
        {
            cin >> x;
            int k = st1.bs(x);
            int ans = n - k - st3.query(k+1,n);
            int dead = 0;
            vector<int> tokills;

            while(1)
            {
                int tok = st2.bs(x);
                if (tok == 0) //???????
                    break;
                change(a[tok], 2e18, tok, 1);
                dead++;
                tokills.pb(tok);
            }
            for (auto tok: tokills)
            {
                change(0, 2e18, tok, 1);   
            }
            cout << dead << ' ';
            cout << ans << endl;
        }
        else
        {
            cin >> x >> y >> z;
            change(x, y, z);
        }
    }
}

/*
4
1 5
2 5
3 100000
4 5
4
1 10000
1 10000
2 3 10 3
1 1000

*/