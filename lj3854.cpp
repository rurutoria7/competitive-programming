#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e4+10, M = 1e5+10, Q = 1e5+10;

int n, m, q;
vector<int> G[N];

signed main()
{
    cin >> n >> m;
    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    //tarjans's ap bcc
    //build vG
    //vGs's LCA
    
    cin >> q;
    while (q--)
    {
        int u, v, m;
        cin >> u >> v >> m;
    }

}
/*
n(2e4) vertex, m(1e5) edge, undirected
q(1e5) queries, s, t, m, answer: if delete m make s, t not connected

bcc -> tree

if
    s, t is belong to different vertex bcc
    and m is ap
    and m is on path of bcc(s), bcc(t):

    yes
else
    no

m on s, t shortest:
s-m shortest
m-t shortest
*/