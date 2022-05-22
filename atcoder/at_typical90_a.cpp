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

const int N = 1e5+10;

int n, k, a[N], l, d[N];

int can (int x){
    int clen = 0;
    rep(i,1,n+1){
        
    }
}

int bs(){
    int i = 0, s = 1e9;
    while (s){
        if (can(i+s)) i+=s;
        else s >>= 1;
    }
    return i+1;
}

signed main(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n+1) d[i] = a[i]-a[i-1];
    cout << bs() << '\n';
}