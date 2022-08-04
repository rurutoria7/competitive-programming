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

int n, a[N], k, t;

signed main()
{
    mothersrosario
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> k;
        rep(i,1,n) cin >> a[i], ans += a[i], a[i] -= (n-i);
        sort(a+1, a+1+n);
        rep(i,1,k) ans -= a[n-i+1], ans -= i-1;
        cout << ans << '\n';
    }
}
/*
n(2e5) ai(1e9)
k del chance, j th del, cost is (n-i)-(k-j)

del a[i], it saves: a[i]-(n-i), choose k biggest
*/
