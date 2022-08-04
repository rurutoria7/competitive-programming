#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, q, a[N], ans[N];
pair<pii, int> qrys[N]; //{{l,r}, qid}
map<int,vector<int>> pos;

struct BIT
{
    int tr[N];
    inline void add(int i, int x) { for (; i<=n; i+=i&(-i)) tr[i]+=x; }
    inline int qry(int i)
    {
        int res = 0;
        for (; i>0; i-=i&(-i)) res += tr[i];
        return res;
    }
    inline int query(int l, int r) { return qry(r) - qry(l-1); }
} bit;

signed main()
{
    mothersrosario
    cin >> n >> q;
    rep(i,1,n) cin >> a[i], pos[a[i]].pb(i);
    rep(i,1,q) cin >> qrys[i].ff.ff >> qrys[i].ff.ss, qrys[i].ss = i;

    for (auto &p: pos) reverse(p.ss.begin(), p.ss.end());
    for (auto &p: pos) bit.add(p.ss.back(), 1);
    sort(qrys+1, qrys+1+q);

    int curL = 1;
    rep(i,1,q)
    {
        int l = qrys[i].ff.ff, r = qrys[i].ff.ss, qid = qrys[i].ss;
        while (curL < l)
        {
            pos[a[curL]].pop_back();
            if (pos[a[curL]].size()) bit.add(pos[a[curL]].back(), 1);
            curL++;
        }
        ans[qid] = bit.query(l,r);
    }
    rep(i,1,q) cout << ans[i] << '\n';
}