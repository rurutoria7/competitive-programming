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
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
distance between a,b
d[a] + d[b] - 2*d[lca(a,b)]
*/
const int N = 2e5+10;
int n, q;
vector<int> G[N];

int p[N][30], d[N];
void dfs (int u){
    for (int i=1; i<30; i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for (auto v: G[u]){
        if (v == p[u][0]){
            continue;
        }
        p[v][0] = u;
        d[v] = d[u]+1;
        dfs(v);
    }
}
int lca (int a, int b){
    if (d[a] < d[b]){
        swap(a,b);
    }
    for (int i=0,t=d[a]-d[b]; t; i++,t>>=1){
        if (t&1){
            a = p[a][i];
        }
    }
    if (a == b){
        return a;
    }
    int s = 29;
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
    minamisan
    cin >> n >> q;
    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1);
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << d[a] + d[b] - 2*d[lca(a,b)] << '\n';
    }
}