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

const int N = 1e5+10;
int n, nrt[N], h[N];
vector<int> G[N];

int dfs (int u){
    int res = 0;
    for (auto v: G[u]){
        res += dfs(v);
        h[u] = max(h[u], h[v]+1);
    }
    return res+h[u];
}
signed main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x, y;
        cin >> x;
        while (x--){
            cin >> y;
            G[i].pb(y);
            nrt[y] = 1;
        }
    }
    for (int i=1; i<=n; i++){
        if (!nrt[i]){
            cout << i << '\n';
            cout << dfs(i) << '\n';
        }
    }

}