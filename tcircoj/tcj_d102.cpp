#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 5e4+10;

vector<int> G[N];
int n;
int dp[N];

void print (int u, int p){
    cout << u << ' ';
    for (auto v: G[u]){
        if (v == p) continue;
        print(v,u);
        cout << u << ' ';
    }
}

signed main(){
    cin >> n;
    int ans = 0;
    rep(i,1,n-1){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb(v);
        G[v].pb(u);
        ans += w;
    }
    rep(i,0,n-1) sort(G[i].begin(), G[i].end());
    cout << ans*2 << '\n';
    print(0,0);
}