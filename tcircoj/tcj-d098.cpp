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

const int N = 1e4+10, M = 1e5+10;

int n, m;
struct E{
    int u, v, w;
} edg[M];

int p[N];
int find (int x){
    return x==p[x]? x:p[x]=find(p[x]);
}

int krus(){
    sort(edg+1,edg+1+m,[](E i, E j){
        return i.w < j.w;
    });
    rep(i,1,n) p[i] = i;
    int cnt = 0, ans = 0;
    rep(i,1,m){
        int u=edg[i].u, v=edg[i].v, w=edg[i].w;
        if (find(u) == find(v)) continue;
        cnt++, ans += w;
        p[find(u)] = find(v);
    }
    return (cnt==n-1? ans:-1);
}

signed main(){
    cin >> n >> m;
    rep(i,1,m){
        int u, v, w;
        cin >> u >> v >> w, u++, v++;
        edg[i] = {u,v,w};
    }
    cout << krus() << '\n';
}