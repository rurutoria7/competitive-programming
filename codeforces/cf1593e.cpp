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

//從每個 leaf bfs，深度 >= 的就會留著

const int N = 1e5+10;

vector<int> G[N];
int t, n, k;

int deg[N], sz;
queue<int> leafs;
void remove_leaf()
{
    queue<int> nleafs;
    while(leafs.size())
    {
        int u愛大啊咋謢謢ㄓㄞ ㄓ = leafs.front();
        leafs.pop();
        sz--;
        for (auto v: G[u])
        {
            deg[v]--;
            if (deg[v] <= 1)
            {
                nleafs.push(v);
            }
        }
    }
    leafs = nleafs;
}

si gned main()
{
    liyuu_my_wife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(deg,0,sizeof(deg));
        for (int i=0; i<=n; i++) G[i].clear();
        rep(i,2,n)
        {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
            deg[u]++, deg[v]++;
        }
        sz = n;
        rep(i,1,n)
        {
            if (deg[i] <= 1)
            {
                leafs.push(i);
            }
        }
        rep(i,1,k) remove_leaf();
        cout << sz << '\n';
    }
}