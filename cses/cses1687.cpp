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

int p[N][30];

//before p[u][0] has filled
//after p[tree[u]][all] filled
void dfs (int u){
    for (int i=1; i<30; i++){
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for (auto v: G[u]){
        p[v][0] = u;
        dfs(v);
    }
}

signed main(){
    cin >> n >> q;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        G[x].pb(i);
    }
    //build p[u][k], u's 2^k th anc
    dfs(1);
    while (q--){
        int x, k;
        cin >> x >> k;
        // answer x's kth anc
        for (int i=0; k>0; i++,k>>=1){
            if (k&1){
                x = p[x][i];
            }
        }
        cout << (x==0? -1:x) << '\n';
    }
}