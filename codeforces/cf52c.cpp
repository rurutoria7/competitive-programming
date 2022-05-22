#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, a[N], q;

struct Seg
{
    int tr[N<<2], lz[N<<2];

    void build (int u=1, int l=0, int r=n)
    {
        if (r-l <= 1)
        {
            tr[u] = a[l];
        }
        else
        {
            int MID = (l+r)/2;
            build(u<<1,l,MID);
            build(u<<1|1,MID,r);
            tr[u] = min(tr[u<<1], tr[u<<1|1]);
        }
    }
    void push (int u)
    {
        tr[u<<1] += lz[u];
        tr[u<<1|1] += lz[u];
        lz[u<<1] += lz[u];
        lz[u<<1|1] += lz[u];
        lz[u] = 0;
    }
    int query (int ql, int qr, int u=1, int l=0, int r=n)
    {
       // de(ql), de(qr), de(u), de(l), de(r), dd;
        if (ql<=l && r<=qr) return tr[u];
        push(u);
        int MID = (l+r)/2, ans = 1e18;
        if (ql<MID) ans = min(ans, query(ql,qr,u<<1,l,MID));
        if (qr>MID) ans = min(ans, query(ql,qr,u<<1|1,MID,r));
        return ans;
    }
    void modify (int ql, int qr, int x, int u=1, int l=0, int r=n)
    {
        if (ql<=l && r<=qr) tr[u] += x, lz[u] += x;
        else
        {
            push(u);
            int MID = (l+r)/2;
            if (ql<MID) modify(ql,qr,x,u<<1,l,MID);
            if (qr>MID) modify(ql,qr,x,u<<1|1,MID,r);
            tr[u] = min(tr[u<<1], tr[u<<1|1]);
        }
    }
} st;

signed main()
{
    liyuu_my_wife
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    st.build();
    cin >> q, cin.ignore();
    while (q--)
    {
        string s;
        getline(cin,s);
        stringstream ss;
        ss.str(s);
        int qry[10], m=0;
        while (ss >> qry[m]) m++;
        qry[1]++;
        if (m == 2)
        {
            if (qry[0]<qry[1]) cout << st.query(qry[0],qry[1]) << '\n';
            else cout << min(st.query(qry[0],n), st.query(0,qry[1])) << '\n';
        }
        else
        {
            if (qry[0]<qry[1]) st.modify(qry[0], qry[1], qry[2]);
            else st.modify(qry[0],n,qry[2]), st.modify(0,qry[1],qry[2]);
        }
        /*
        rep(i,1,7)
        {
            de(i), de(st.tr[i]), de(st.lz[i]), dd;
        }
        */
    }
}


/*
>
modify[l,r) //increase
query[l,r) //minimum

n = 2e5

?
if l <= r, [l,r)
if r<l, [l,n), [0,r)

?
segment tree, 0 index, [), range add
r++ when input

4
1 2 3 4
2
3 0 -1
2 1

*/