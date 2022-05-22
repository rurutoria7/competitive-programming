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

const int N = 110;

vector<int> G[N];
int n, m, op;

queue<int> q;
int d[N], ans, cnt;
void bfs(){
    memset(d,-1,sizeof(d));
    q.push(op);
    d[op] = 0, cnt = -1;
    while (q.size()){
        int u = q.front();
        q.pop();
        cnt++;
        ans += d[u];
        for (auto v: G[u]){
            if (d[v]>=0) continue;
            d[v] = d[u]+1;
            q.push(v);
        }
    }
}

signed main(){
    cin >> n >> m >> op;
    for (int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
    }
    bfs();
    cout << cnt << '\n' << ans << '\n';
}