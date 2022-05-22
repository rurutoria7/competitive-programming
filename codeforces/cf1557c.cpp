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

const int N = 2e5+10, M = 1e9+7;

int t, n, k;
int b1p, b0p, a1p, a0p, dp[N];
int fac[N], inv[N];

inline int qpow (int x, int y){
    int res = 1;
    for (; y; y>>=1){
        if (y&1){
            res = res*x%M;
        }
        x = x*x%M;
    }
    return res;
}

inline int whatever (int x){
    return qpow(2,n*x);
}

signed main(){
    // pre
    fac[0] = 1, inv[0] = 1;
    for (int i=1; i<N; i++){
        fac[i] = fac[i-1]*i%M;
        inv[i] = qpow(fac[i],M-2);
    }
    cin >> t;
    while (t--){
        cin >> n >> k;

        // calc b1p, b0p, a1p, a0p
        b1p = 0, b0p = 0;
        for (int i=1; i<=n; i+=2){
            b1p = (b1p + fac[n]*inv[i]%M*inv[n-i]%M)%M; // fac[1] = inv[1] = 1
        }
        for (int i=0; i<=n; i+=2){
            b0p = (b0p + fac[n]*inv[i]%M*inv[n-i]%M)%M;
        }
        a1p = 1;
        a0p = (qpow(2,n)-1+M)%M;

        //cout << b1p << ' '  << b0p << ' ' << a1p << ' ' << a0p << '\n';
        // dp
        for (int i=1; i<=k; i++){
            dp[i] = n%2*dp[i-1];
            dp[i] = (dp[i] + (b0p-(n%2==0)+M)%M*dp[i-1]%M)%M;
            dp[i] = (dp[i] + (b1p-(n%2==1)+M)%M*whatever(i-1)%M)%M;
        }

        // cout << all_pos - dp[k]
        cout << (whatever(k) - dp[k] + M)%M << '\n';
    }
}