#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const double PI = acos(-1);
int v, s;

signed main()
{
    cin >> v >> s;
    double theta = 2*PI/v;
    double r2 = -s*s*1.0/(-2+2*cos(theta));
    cout << fixed << setprecision(-10) << r2*PI << endl;
}