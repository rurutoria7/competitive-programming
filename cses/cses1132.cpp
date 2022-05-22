#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define rr7 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

vector<int> G[N];
int h1[N], h2[N], mson[N], n;

void upd (int u, int h, int v)
{
    if (h > h1[u])
    {
        mson[u] = v;
        h2[u] = h1[u];
        h1[u] = h;
    }
    else if (h > h2[u])
    {
        h2[u] = h;
    }
}

void dfs1 (int u, int p)
{
    for (auto v: G[u])
    {
        if (v == p)
            continue;
        dfs1(v,u);
        upd(u,h1[v]+1,v);
    }
}
void dfs2 (int u, int p)
{
    if (u == 1);
    else if (mson[p] == u)
        upd(u,h2[p]+1,p);
    else
        upd(u,h1[p]+1,p);
    for (auto v: G[u])
    {
        if (v == p)
            continue;
        dfs2(v,u);
    }
}

signed main()
{
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for (int i=1; i<=n; i++)
        cout << h1[i] << "\n "[i+1<=n];
}