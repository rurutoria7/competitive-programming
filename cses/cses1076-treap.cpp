#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define last(x) (prev(x.end()))
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, k, a[N];

struct Treap
{
    int pri[N], sz[N], val[N], l[N], r[N];
    int rt, cnt;
    unsigned owo=17;

    int gen (int x)
    {
        cnt++;
        pri[cnt] = (owo=owo*0xdefaced+1);
        sz[cnt] = 1;
        val[cnt] = x;
        return cnt;
    }
    void pull (int u)
    {
        sz[u] = sz[l[u]] + sz[r[u]] + 1;
    }
    void split (int u, int i, int &a, int &b)
    {
        if (!u)
        {
            a = b = 0;
            return;
        }
        if (sz[l[u]]+1 <= i)
        {
            a = u;
            split(r[u],i-sz[l[u]]-1,r[u],b);
        }
        else
        {
            b = u;
            split(l[u],i,a,l[u]);
        }
        pull(u);
    }
    int merge (int u, int v)
    {
        if (!u || !v) return max(u,v);
        if (pri[v]<pri[u])
        {
            l[v] = merge(u,l[v]);
            pull(v);
            return v;
        }
        else
        {
            r[u] = merge(r[u],v);
            pull(u);
            return u;
        }
    }
    int find_by_order (int i, int u)
    {
        if (i <= sz[l[u]])
            return find_by_order(i,l[u]);
        else if (i >  sz[l[u]]+1)
            return find_by_order(i-sz[l[u]]-1,r[u]);
        else 
            return u;
    }
    int find_by_order (int i){ return find_by_order(i,rt); }
    int get_rk (int x, int u) //how much node in the tree < x
    {
        if (!u) return 0;
        if (val[u] < x)
            return get_rk(x,r[u])+sz[l[u]]+1;
        else
            return get_rk(x,l[u]);
    }
    int get_rk (int x){ return get_rk(x,rt); }
    void insert (int x)
    {
        int i = get_rk(x), t1, t2;
        split(rt,i,t1,t2);
        rt = merge(t1,merge(gen(x),t2));
    }
    void erase (int x)
    {
        int i = get_rk(x), t1, t2, t3, t4;
        split(rt,i,t1,t2);
        split(t2,1,t3,t4);
        rt = merge(t1,t4);
    }
} trp;

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];

    rep(i,1,n)
    {
        trp.insert(a[i]);
        if (i>k)
            trp.erase(a[i-k]);
        if (i>=k)
            cout << trp.val[trp.find_by_order((k-1)/2+1)] << "\n "[i+1<=n];
    }
}