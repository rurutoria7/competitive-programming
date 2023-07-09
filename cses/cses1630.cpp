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

int n, a[N], d[N];

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> d[i] >> a[i];

    int res = 0;
    sort(d+1, d+1+n);
    rep(i,1,n) d[i] += d[i-1];
    rep(i,1,n) res += a[i]-d[i];
    cout << res << '\n';
}