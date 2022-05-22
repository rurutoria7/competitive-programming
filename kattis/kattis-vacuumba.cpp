#include <bits/stdc++.h>
#define double long double
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
const double PI = acos(-1);
int n, t;

signed main(){
    liyuu_my_wife
    cin >> t;
    while (t--){
        cin >> n;
        double x=0, y=0, theta=PI/2;
        while (n--){
            double rot, len;
            cin >> rot >> len;
            theta += rot*PI/180;
            x += cos(theta)*len;
            y += sin(theta)*len;
        }
        cout << fixed << setprecision(10) << x << ' ' << y << '\n';
    }
}