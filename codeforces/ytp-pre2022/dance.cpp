#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cerr << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, M = 2e5+10;

int n, m, a[N];

vector<pii> G[N];
vector<int> ans;

signed main()
{
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb({i,v});
        G[v].pb({i,u});
    }
    int rt = 0, id = 0;
    rep(i,1,n)
    {
        if (G[i].size() == 1)
        {
            rt = i;
            id = G[i][0].ff;
            break;
        }
    }
    
    int u = rt, v = G[rt][0].ss;
    while (1)
    {
        //de(u), de(id), de(v), dd
        if (a[u])
        {
            ans.pb(id);
            a[v] ^= 1;
        }

        if (G[v].size() == 1)
        {
            if (a[v] == 0)
            {
                cout << "Yes\n" << ans.size() << '\n';
                for (auto p: ans) cout << p << ' ';
                cout << '\n';
            }
            else
            {
                cout << "No\n";
            }
            return 0;
        }
        pii ne = (G[v][0].ff == id? G[v][1] : G[v][0]);
        u = v;
        v = ne.ss;
        id= ne.ff;        
    }
}
/*
choose set of edge, 
let every node have even or odd edge choose
*/

/*
4
3
0 0 0 0
1 2
2 4
4 3
*/