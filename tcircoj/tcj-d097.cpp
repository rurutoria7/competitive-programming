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

int n, m, k;
int G[N][N];

pii p[N][N];
int sz[N][N], tot, mxsz;
void init (){
    rep(i,1,m)
        rep(j,1,n)
            p[i][j] = {i,j}, sz[i][j]=1;
}
pii find (pii i){
    return p[i.ff][i.ss]==i? i:p[i.ff][i.ss]=find(p[i.ff][i.ss]);
}
void U (pii i, pii j){
    //de(i.ff), de(i.ss), de(j.ff), de(j.ss), de(G[i.ff][i.ss]), de(G[j.ff][j.ss]), dd;
    if (G[i.ff][i.ss]==0 || G[j.ff][j.ss]==0)
        return;
    
    pii irt = find(i), jrt = find(j);
    if (irt == jrt) return;
    p[irt.ff][irt.ss] = jrt;
    sz[jrt.ff][jrt.ss] += sz[irt.ff][irt.ss];
    tot--;
    mxsz = max(mxsz, sz[jrt.ff][jrt.ss]);
}

signed main(){
    minamisan
    cin >> m >> n >> k;
    rep(i,1,m)
        rep(j,1,n)
            cin >> G[i][j], tot+=G[i][j], mxsz=max(mxsz,G[i][j]);
    init();
    /*
    rep(i,1,m){
        rep(j,1,n) cout << G[i][j] << ' ';
        cout << '\n';
    }
    */
    rep(i,1,m)
        rep(j,1,n){
            U({i,j},{i+1,j});
            U({i,j},{i,j+1});
            U({i,j},{i-1,j});
            U({i,j},{i,j-1});
            //de(mxsz), de(tot), dd;
        }
    int ans1=mxsz, ans2=tot;
    while (k--){
        int i, j;
        cin >> i >> j;
        if (G[i][j]) continue;
        G[i][j] = 1;
        tot++, mxsz=max(mxsz,1LL);
        U({i,j},{i+1,j});
        U({i,j},{i,j+1});
        U({i,j},{i-1,j});
        U({i,j},{i,j-1});
        ans1 += mxsz;
        ans2 += tot;
    }
    cout << ans1 << '\n' << ans2 << '\n';
}