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

const int N = 2e5+10;

int a[N], n;

int ceil (int x, int y){ return (x-1)/y+1; }

int valid (int k, int p, int q)
{
    return max(0LL,p-k) <= min(2*k-q,k); 
}

int bs (int p, int q)
{
    int i = 0, s = 1e7;
    while (s)
    {
        if (valid(i+s, p, q)) s >>= 1;
        else i += s;
    }
    return i+1;
}

signed main()
{
    mothersrosario
    cin >> n;
    rep(i,1,n) cin >> a[i];

    int ans = 2e9, mn1 = 2e9, mn2 = 2e9;

    rep(i,1,n)
    {
        if (i<n) ans = min(ans, bs(a[i],a[i+1]));
        if (i<n-1) ans = min(ans, ceil(a[i]+a[i+2], 2));
        if (a[i] <= mn1) mn2 = mn1, mn1 = a[i];
        else if (a[i] < mn2) mn2 = a[i];
    }
    cout << min(ans, ceil(mn1,2)+ceil(mn2,2)) << '\n';
}
