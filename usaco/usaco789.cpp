#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, Q = 1e5+10;
 
/*
sort edges by w (less)
sort queries (less)
*/



struct DSU
{
    int p[N], sz[N], n;
    DSU(int _n){ n = _n; rep(i,1,n) p[i] = i, sz[i] = 1; }
    int find(int i){ return (p[i]==i? i : p[i]=find(p[i])); }
    void U(int i, int j){ sz[find(i)] += sz[find(j)], p[find(j)] = find(i); }
    int size(int i){ return sz[find(i)]; }
};

pair<int,pii> edges[N], queries[Q];
int n, q, ans[Q];

signed main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    lyx_my_wife
    cin >> n >> q;
    rep(i,1,n-1) cin >> edges[i].ss.ff >> edges[i].ss.ss >> edges[i].ff;
    rep(i,1,q) cin >> queries[i].ff >> queries[i].ss.ff, queries[i].ss.ss = i;
    sort(edges+1, edges+n);
    sort(queries+1, queries+1+q);

    DSU dsu(n);
    for (int i=q, j=n-1; i>0; i--)
    {
        int k = queries[i].ff, u = queries[i].ss.ff, qid = queries[i].ss.ss;
        while(j > 0 && edges[j].ff >= k)
        {
            dsu.U(edges[j].ss.ff, edges[j].ss.ss);
            j--;
        }
        ans[qid] = dsu.size(u);
    }
    rep(i,1,q) cout << ans[i]-1 << endl;
}