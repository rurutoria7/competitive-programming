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

const int N = 5e7;

int a, b, c, r0, r1, n, p;
int f[N];
map<pii,int> mp; //{{f[i-1], f[i]}, i}

signed main(){
    cin >> a >> b >> c >> f[0] >> f[1] >> n >> p;
    a%=p, b%=p, c%=p, f[0]%=p, f[1]%=p;
    mp[{f[0],f[1]}] = 1;

    int op, len;
    rep(i,2,N){
        f[i] = ((a*f[i-1]*f[i-2]%p + b*f[i-1]%p + c*f[i-2]%p)%p+p)%p;
        if (mp[{f[i-1],f[i]}] != 0){
            op = mp[{f[i-1],f[i]}];
            len = i - op;
            break;
        }
        else
            mp[{f[i-1],f[i]}] = i;
    }
    if (n <= op+len) cout << f[n] << '\n';
    else cout << f[(n-op)%len+op] << '\n';
}