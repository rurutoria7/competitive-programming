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

const int N = 1e5+10;

int n, a[N], dp[N], ans;

signed main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    for (int i=1; i<=n; i++){
        dp[i] = max(dp[i-1],0LL) + a[i];
        ans = max(ans, dp[i]);
    }    

    cout << ans << '\n';
}