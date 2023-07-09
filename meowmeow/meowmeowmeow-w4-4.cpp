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

int a, b, c, d, m, s, t;

int ceil(int x, int y)
{
    return x/y + ((x%y)!=0);
}

int how_fast(int x)
{
    int d2 = min(s, (m+d*x)/c*b), d3 = s-d2;
    return ceil(d2,b) + ceil(d3,a) + x;
}

int how_far(int x)
{
    int t2 = min(t-x, (m+d*x)/c), t3 = t-x-t2;
    return b*t2 + a*t3;
}

signed main()
{
    cin >> a >> b >> c >> d >> m >> s >> t;
    int mx = 0, mn = 9e18;
    rep(x,0,t)
    {
        mx = max(mx, how_far(x));
        mn = min(mn, how_fast(x));
    }
    if (mn <= t) cout << "Yes\n" << mn << '\n';
    else cout << "No\n" << mx << '\n';
}