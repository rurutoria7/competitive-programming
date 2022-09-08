#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
dp[vis][i]: start from m, walk to i, vis has visited
dp[vis][i] = min(dp[vis^(1<<i)][somewhere x is visited] + dis[x][i]
*/
const int N = 17;
int dp[1<<N][N], d[N][N];
int n, m;

signed main(){
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> d[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1<<m][m] = 0;
    int ans = 9e18;
    for (int v=0; v<(1<<n); v++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (j!=i && (v&(1<<j))){
                    dp[v][i] = min(dp[v][i], dp[v^(1<<i)][j]+d[i][j]);
                }
            }
            if (v == (1<<n)-1){
                ans = min(ans, dp[v][i]+d[i][m]);
            }
        }
    }
    cout << ans << '\n';
}