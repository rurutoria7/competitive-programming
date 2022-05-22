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

const int N = 100;

int a, n, m, x;
pii gain[N];

signed main(){
    cin >> a >> n >> m >> x;
    if (x == 1){
        cout << a << '\n';
    }
    else if (x == 2){
        cout << a << '\n';
    }
    else if (x == 3){
        cout << 2*a << '\n';
    }
    else{
        gain[1] = {1,0};
        gain[2] = {0,0};
        gain[3] = {1,0};
        gain[4] = {0,1};
        rep(i,5,n-1){
            gain[i].ff = gain[i-1].ff + gain[i-2].ff;
            gain[i].ss = gain[i-1].ss + gain[i-2].ss;
        }
        rep(i,2,n-1){
            gain[i].ff += gain[i-1].ff;
            gain[i].ss += gain[i-1].ss;
        }
        int y = (m-gain[n-1].ff*a)/gain[n-1].ss;
        cout << a*gain[x].ff + y*gain[x].ss << '\n';
    }
}