#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 10;

int h;
int a[N];

signed main(){
    rep(i,1,N) cin >> a[i];
    cin >> h;
    int res = 0;
    rep(i,1,N){
        if (a[i] <= h+30){
            res++;
        }
    }
    cout << res << '\n';
}