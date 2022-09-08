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

const int N = 1010;

int dp[N], n, m;

signed main(){
    minamisan
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i=1; i<N; i++){
        if (i>=50) dp[i] = min(dp[i-50]+1, dp[i]);
        if (i>=10) dp[i] = min(dp[i-10]+1, dp[i]);
        if (i>=5) dp[i] = min(dp[i-5]+1, dp[i]);
        dp[i] = min(dp[i-1]+1, dp[i]);
    }
    
    cin >> m;
    while (m--){
        cin >> n;
        cout << dp[n] << '\n';
    }
}