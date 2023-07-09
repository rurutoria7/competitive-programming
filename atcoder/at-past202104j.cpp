#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

double EPS = 1e-10;

int n, c;
pii a[N];

double calc(double x)
{
    double res = 0;
    rep(i,1,n)
    {
        res += (x-a[i].ff)*(x-a[i].ff) + (c-a[i].ss)*(c-a[i].ss);
    }
    return res;
}

double ts()
{
    double l = -1e5, r = 1e5;
    
    while (r-l > EPS)
    {
        double t1 = (l*2+r)/3, t2 = (l+r*2)/3;
        if (calc(t1) > calc(t2)) l = t1;
        else r = t2;
    }
    return calc(l);
}

signed main()
{
    cin >> n >> c;
    rep(i,1,n) cin >> a[i].ff >> a[i].ss;
    cout << setprecision(11) << fixed << ts() << '\n';
}