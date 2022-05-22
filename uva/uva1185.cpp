#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int t, n;

signed main(){
    liyuu_my_wife
    cin >> t;
    while (t--){
        cin >> n;
        long double res = 0;
        rep(i,1,n){
            res += log10(i);
        }
        cout << (int)res+1 << '\n';
    }
}