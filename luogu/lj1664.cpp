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

const int N = 1e3+10;

int a[N], n;

int score (int i){
    if (i >= 360) return 6;
    if (i >= 120) return 5;
    if (i >= 30) return 4;
    if (i >= 7) return 3;
    if (i >= 3) return 2;
    if (i >= 1) return 1;
}

signed main(){
    cin >> n;
    rep(i,1,n){
        cin >> a[i];
    }
    int lx=0, sum=0, blx = 0;
    rep(i,1,n){
        if (a[i] == 0) blx++, blx = min(blx, 15LL);
        else{
            if (a[i-1]==0) lx = max(0LL, lx-(1LL<<(blx-1)));
            blx = 0;
            lx++;
            sum += score(lx);
        }
    }
    cout << sum << "\n";
}