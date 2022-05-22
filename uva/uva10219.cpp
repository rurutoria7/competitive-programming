#include <bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int n, k;

signed main(){
    liyuu_my_wife
    while (cin >> n >> k){
        double res = 0;
        if (n-k > n/2) k = n-k;
        rep(i,k+1,n){
            res += log10(i);
        }
        rep(i,1,n-k){
            res -= log10(i);
        }
        cout << (int)(res)+1 << '\n'; 
    }    
}