#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));

const int MAXN = 105;
const int Mod = 1e9 + 7;
int c, s, q, v, u, d, a, b, cnt = 1;
int G[MAXN][MAXN], dp[MAXN][MAXN];

signed main(){
    opt;
    while( cin >> c >> s >> q && ( c || s || q ) ){
        if (cnt != 1) cout << '\n';
        cout << "Case #" << cnt++ << "\n";
        mem(G);
        for( int i = 0 ; i < s ; i++ ){
            cin >> u >> v >> d;
            G[u][v] = d;
            G[v][u] = d;
        }

        for( int i = 1 ; i <= c ; i++ ){
            for( int j = 1 ; j <= c ; j++ ){
                dp[i][j] = G[i][j];
            }
        }

        for( int k = 1 ; k <= c ; k++ ){
            for( int i = 1 ; i <= c ; i++ ){
                for( int j = 1 ; j <= c ; j++ ){
                    if (i == k || k == j || i == j) continue;
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                }
            }
        }

        for( int i = 0 ; i < q ; i++ ){
            cin >> a >> b;
            if( dp[a][b] < 1e9 ) cout << dp[a][b] << "\n";
            else cout << "no path\n";
        }
    }
}