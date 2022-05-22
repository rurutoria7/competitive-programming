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
int sz[N], sum[N], n;

void dfs1 (int u, int p)
{
    sz[u] = 1;
    for (auto v: G[u])
    {
        if (v == p)
            continue;
        dfs1(v,u);
        sz[u] += sz[v];
        sum[u] += sum[v]+sz[v];
    }
}
void dfs2 (int u, int p)
{
    if (u!=p)
        sum[u] = sum[p] + n - 2*sz[u];
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
    for (int i=1; i<=n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for (int i=1; i<=n; i++)
        cout << sum[i] << "\n "[i+1<=n];
}