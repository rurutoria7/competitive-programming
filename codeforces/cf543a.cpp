#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 510;

int dp[2][N][N], n, m, b, M, a[N];

signed main()
{
    lyx_my_wife
    cin >> n >> m >> b >> M;
    rep(i,1,n) cin >> a[i];

    int ans = 0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            rep(k,0,b)
            {
                int &d = dp[i%2][j][k];
                if (j == 0 && k == 0) d = 1;
                else if (j == 0 || i == 0) d = 0;
                else
                {
                    d = dp[(i-1)%2][j][k];
                    if (k >= a[i]) d += dp[i%2][j-1][k-a[i]], d%=M;
                }
                if (i == n && j == m) ans = (ans+d)%M;
            }
        }
    }

    cout << ans << endl;
}
/*
dp[i][j][k]: people 1..n, write task 1..j, total bug k, posibilities

dp[i][j][k] = dp[i][j-1][k-a[i]] + dp[i-1][j][k]

dp[0][0][0] = 1
dp[0][0][j] = 0
dp[0][j][k] = 0
dp[0][j][0] = 0

dp[i][0][0] = 1
dp[i][0][k] = 0

*/