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

int dp[N][2], w[N], n;
vector<int> G[N];

void dfs (int u){
    dp[u][1] += w[u];
    for (auto v: G[u]){
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][1],dp[v][0]);
    }
}

signed main(){
    cin >> n >> w[1];
    for (int i=2; i<=n; i++){
        int p;
        cin >> p >> w[i];
        G[p].pb(i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
