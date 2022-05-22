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

const int N = 1e5+10, M = 1e9+7;

int n, m;
vector<pii> G[N]; //{w,v}

priority_queue<pii,vector<pii>,greater<pii>> pq;
int d[N], sum[N], mx[N], mn[N];
void dijks (int op){
    memset(d,0x3f,sizeof(d));
    d[op] = 0;
    sum[op] = 1;
    pq.push({0,op});

    while (pq.size()){
        pii u = pq.top();
        pq.pop();
        for (auto e: G[u.ss]){
            if (d[e.ss] > u.ff+e.ff){
                d[e.ss] = u.ff+e.ff;
                sum[e.ss] = sum[u.ss];
                mx[e.ss] = mx[u.ss]+1;
                mn[e.ss] = mn[u.ss]+1;
                pq.push({d[e.ss], e.ss});
            }
            else if (d[e.ss] == u.ff+e.ff){
                sum[e.ss] = (sum[e.ss] + sum[u.ss])%M;
                mx[e.ss] = max(mx[e.ss], mx[u.ss]+1);
                mn[e.ss] = min(mn[e.ss], mn[u.ss]+1);
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w,v});
    }
    dijks(1);
    cout << d[n] << ' ' << sum[n] << ' ' << mn[n] << ' ' << mx [n] << '\n';
}
