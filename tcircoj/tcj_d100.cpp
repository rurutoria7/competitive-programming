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

const int N = 1e4+10;

int T, n, m;
vector<int> G[N];

string ans;
int d[N];
void dfs (int u){
    for (auto v: G[u]){
        if (d[v]){
            if (d[v]%2 == d[u]%2){
                ans = "no";
            }
        }
        else{
            d[v] = d[u]+1;
            dfs(v);
        }
    }
}

signed main(){
    minamisan
    cin >> T;
    while (T--){
        //init
        memset(d,0,sizeof(d));
        rep(i,1,n) G[i].clear();
        cin >> n >> m;
        rep(i,1,m){
            int u, v;
            cin >> u >> v;
            u++, v++;
            G[u].pb(v);
            G[v].pb(u);
        }

        ans = "yes";
        rep(i,1,n){
            if (!d[i]){
                d[i] = 1;
                dfs(i);
            }
        }
        cout << ans << '\n';
    }
}