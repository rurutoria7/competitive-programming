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

int n, k, a[N];

int v[N], m;
void lisan()
{
    rep(i,1,n) v[i] = a[i];
    sort(v+1,v+1+n);
    m = unique(v+1,v+1+n)-v-1;
    rep(i,1,n) a[i] = lower_bound(v+1,v+1+m,a[i])-v;
}

struct Seg
{
    int tr[N<<2];
    void modify (int p, int x, int u=1, int l=1, int r=m)
    {
        if (l==p && p==r)
        {
            tr[u] += x;
            return;
        }
        int mid = (l+r)/2;
        if (p<=mid) modify(p,x,u*2,l,mid);
        else modify(p,x,u*2+1,mid+1,r);
        tr[u] = tr[u*2] + tr[u*2+1];
    }
    int query (int x, int u=1, int l=1, int r=m)
    {
        if (l == r)
            return l;
        int mid = (l+r)/2;
        if (tr[u*2] >= x) return query(x,u*2,l,mid);
        else return query(x-tr[u*2],u*2+1,mid+1,r);
    }
} seg;

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    lisan();
    rep(i,1,n)
    {
        seg.modify(a[i],1);
        if (i > k)
            seg.modify(a[i-k],-1);
        if (i>=k)
            cout << v[seg.query((k-1)/2+1)] << "\n "[i+1<=n];
    }
}