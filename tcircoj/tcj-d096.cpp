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

int n, m;
vector<pii> G[N];

int dis[N];
queue<pii> q;
void dijks(){
    memset(dis,0x3f,sizeof(dis));
    q.push({0,1});
    dis[1] = 0;
    while (!q.empty()){
        int u = q.front().ss;
        int d = q.front().ff;
        q.pop();
        for (auto v: G[u]){
            if (dis[v.ss] > d+v.ff){
                dis[v.ss] = d+v.ff;
                q.push({dis[v.ss], v.ss});
            }
        }
    }
}  

signed main(){
    cin >> n >> m;
    rep(i,1,m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u+1].pb({w,v+1});
        G[v+1].pb({w,u+1});
    }
    dijks();
    
    int cnt=0, mxd=0;
    rep(i,1,n){
        if (dis[i]>1e18){
            cnt++;
        }
        else mxd = max(mxd, dis[i]);
    }
    cout << mxd << '\n' << cnt << '\n';
}