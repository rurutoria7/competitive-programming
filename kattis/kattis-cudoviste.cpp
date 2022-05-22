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

const int N = 100;

int G[N][N], n, m, ans[10];

signed main(){
    cin >> n >> m;
    rep(i,1,n){
        rep(j,1,m){
            char c;
            cin >> c;
            G[i][j] = (c=='#'? 0:(c=='X'? 1:2));
        }
    }
    rep(i,1,n-1){
        rep(j,1,m-1){
            if (G[i][j] && G[i+1][j] && G[i][j+1] && G[i+1][j+1]){
                int ya_lan = (G[i][j]==1) + (G[i+1][j]==1) + (G[i][j+1]==1) + (G[i+1][j+1]==1);
                ans[ya_lan]++;
            }
        }
    }
    rep(i,0,4) cout << ans[i] << '\n';   
}