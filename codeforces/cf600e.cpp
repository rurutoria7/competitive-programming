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

const int N = 1e5+10;

int c[N], n;
vector<int> G[N];

int ans[N], sum[N], mxcnt[N];
map<int,int> cnt[N];

inline void add (int u, pii x)
{
    cnt[u][x.ff] += x.ss;
    if (cnt[u][x.ff] > mxcnt[u])
        mxcnt[u] = cnt[u][x.ff], sum[u] = x.ff;
    else if (cnt[u][x.ff] == mxcnt[u])
        sum[u] += x.ff;
}

void calc (int u, int p)
{
    int mxson = 0, mxsz = 0;
    for (auto v: G[u])
    {
        if (v!=p)
            calc(v,u);
        if (cnt[v].size() > mxsz)
            mxsz = cnt[v].size(), mxson = v;
    }

    swap(cnt[u], cnt[mxson]);
    sum[u] = sum[mxson];
    mxcnt[u] = mxcnt[mxson];

    for (auto v: G[u])
    {
        if (v == mxson || v == p) continue;
        for (auto x: cnt[v])
            add(u,x);
    }
    add(u,{c[u],1});
    ans[u] = sum[u];
}

signed main()
{
    liyuu_my_wife
    cin >> n;
    rep(i,1,n) cin >> c[i];
    rep(i,2,n)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    calc(1,1);
    rep(i,1,n) cout << ans[i] << ' ';
}
/*
given a tree, for i=1~n output sum of dominating color
dominating is the most color in subtree
---
for node u, map<int,int> cnt, sum, mxcnt
u: v1, v2
u = merge(v1, v2), add u
merge(v1, v2)
    v1 size is bigger
    for (auto x: v2)
        v1.add(x)
    return  v1
*/