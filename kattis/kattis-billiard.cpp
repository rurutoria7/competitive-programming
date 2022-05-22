#include <bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const double PI = acos(-1);
double a, b, s, m, n;

signed main(){
    liyuu_my_wife
    while (cin >> a >> b >> s >> m >> n, a||b||s||m||n){
        double x = a*m, y = b*n;
        cout << fixed << setprecision(2) << atan(y/x)/PI*180 << ' ' << sqrt(x*x+y*y)/s << '\n';
    }
}