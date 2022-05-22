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

int n, q;
vector<int> G[N];

int d[N], p[N][30];
void dfs (int u){
    for (int i=1; i<30; i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for (auto v: G[u]){
        d[v] = d[u]+1;
        p[v][0] = u;
        dfs(v);
    }
}

int query (int a, int b){
    // d[a] > d[b]
    if (d[b] > d[a]){
        swap(a,b);
    }
    // d[a] == d[b]
    for (int t=d[a]-d[b],i=0; t; t>>=1,i++){
        if (t&1){
            a = p[a][i];
        }
    }
    if (a == b){
        return a;
    }
    // find min(d[c]), c is anc of a, b
    int s=29;
    while (s >= 0){
        if (p[a][s] == p[b][s]){
            s--;
        }
        else{
            a = p[a][s];
            b = p[b][s];
        }
    }
    return p[a][0];
}

signed main(){
    rr7
    cin >> n >> q;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        G[x].pb(i);
    }
    dfs(1);
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << query(a,b) << '\n';
    }
}