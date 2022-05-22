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

const int N = 510;

int dp[N][N], m, n;
char c[N][N];
int sh[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int d[N][N];
queue<pii> q;

int legal (pii x){
    return (1<=x.ff && x.ff<=m &&
            1<=x.ss && x.ss<=n &&
            c[x.ff][x.ss]!='1' && d[x.ff][x.ss]<0);
}

void bfs(){
    memset(d,-1,sizeof(d));
    q.push({1,1});
    d[1][1] = 0;
    while (q.size()){
        pii u = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            for (pii v = {u.ff+sh[i][0],u.ss+sh[i][1]};
            legal(v); v.ff+=sh[i][0],v.ss+=sh[i][1]){
                q.push(v);
                d[v.ff][v.ss] = d[u.ff][u.ss]+1;
            }
        }
    }
}

signed main(){
    cin >> m >> n;
    rep(i,1,m)
        rep(j,1,n)
            cin >> c[i][j];
    bfs();
    cout << (d[m][n]<0? -1:d[m][n]-1) << '\n';
}