#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 15;

int a[N], t, n, dp[N];

int qpow (int i, int j){
    int ans = 1;
    for (; j; j>>=1,i=i*i){
        if (j&1) ans *= i;
    }
    return ans;
}

signed main(){
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        n = s.size();
        rep(i,1,n){
            a[i] = s[i-1]-'0';
        }
        dp[n+1] = 0;
        for (int i=n; i>0; i--){
            dp[i] = dp[i+1] + (a[i]-(a[i]>=7))*qpow(9,n-i);
        }
        cout << dp[1] << '\n';
    }
}