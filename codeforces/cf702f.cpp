#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define luckier ios::sync_with_stdio(0), cin.tie(0);
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, m, b[N], ans[N];
pii qc[N];

struct Treap
{
    int lc[N<<2], rc[N<<2], pri[N<<2], val[N<<2], ktag[N<<2], vtag[N<<2], cnt;
    pii key[N]; //b[i] and i

    int newTreap(int _key, int _val, int _idx)
    {
        cnt++;
        key[cnt] = mp(_key, _idx);
        val[cnt] = _val;
        vtag[cnt] = ktag[cnt] = 0;
        pri[cnt] = rand();
        return cnt;
    }
    void upd(int u, int kadd, int vadd)
    {
        key[u].ff += kadd, ktag[u] += kadd;
        val[u] += vadd, vtag[u] += vadd;
    }
    void pull(int u)
    {

    }
    void push(int u)
    {
        upd(lc[u], ktag[u], vtag[u]);
        upd(rc[u], ktag[u], vtag[u]);
        ktag[u] = vtag[u] = 0;
    }
    void split(int u, pii k, int &a, int &b) // split u to <k , >k as a, b
    {
        push(u);
        if (!u) a = b = 0;
        else if (key[u] > k) split(lc[u], k, a, lc[u]), b = u;
        else split(rc[u], k, rc[u], b), a = u;
        pull(u);
    }
    int merge(int a, int b)
    {
        push(a), push(b);
        if (!a || !b) return (a? a:b);
        if (pri[a] < pri[b])
        {
            rc[a] = merge(rc[a], b), pull(a);
            return a;
        }
        else
        {
            lc[a] = merge(a, lc[b]), pull(b);
            return b;
        }
    }
    int insert(int u, int x)
    {
        int a, b;
        split(u, key[x], a, b);
        debug(u), dd
        cout << "splited\n";
        debug(a), dd
        debug(b), dd;

        a = merge(a, x);
        cout << "merged 1\n";
        debug(a), dd

        a = merge(a, b);
        cout << "merged all\n";
        debug(a), dd
        return a;
    }
    int force_merge(int a, int b)
    {
        if (!b) return a;
        a = force_merge(a, lc[b]);
        a = force_merge(a, rc[b]);
        lc[b] = rc[b] = 0;
        return insert(a, b);
    }
    void extract_ans(int u)
    {
        if (!u) return;
        ans[key[u].ss] = val[u];
        extract_ans(lc[u]);
        extract_ans(rc[u]);
    }
    void debug(int u)
    {
        if (!u) return;
        de(u), de(key[u].ff), de(key[u].ss), de(lc[u]), de(rc[u]), de(val[u]), de(ktag[u]), de(vtag[u]), dd
        debug(lc[u]);
        debug(rc[u]);
    }
} tp;

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> qc[i].ss >> qc[i].ff, qc[i].ff *= -1;
    cin >> m;
    rep(i,1,m) cin >> b[i];
    
    sort(qc+1, qc+1+n);

    int rt;
    rep(i,1,m)
    {
        de(i), dd
        if (i == 1) rt = tp.newTreap(b[i], 0, i);
        else rt = tp.insert(rt, tp.newTreap(b[i], 0, i));
        //tp.debug(rt), dd
    }

    // tp.debug(rt);

    rep(i,1,n)
    {
        int x, y, mn, y2;
        tp.split(rt, mp(qc[i].ss, 0), x, y);
        tp.upd(y, -qc[i].ss, 1);
        tp.split(y, mp(2*qc[i].ss, 0), y, y2);
        x = tp.force_merge(x, y);
        x = tp.merge(x, y2);
    }
    tp.extract_ans(rt);
    rep(i,1,m) cout << ans[i] << '\n';
}
/* 
1. sort by quality, less
2. for every query bi, scan back, buy as long as can by
3. scan back, some can buy som can not buy
    treap, key by "money"
    for every items price c[i]:
        split two treap, <c[i], >=c[i] as x, y
        for every node in treap y, key -= c[i], val += 1
        while first node in treap y as mn:
            split it out
            add to x
*/