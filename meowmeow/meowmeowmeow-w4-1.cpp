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

int n, x;
pii a[N];

signed main()
{
    cin >> n >> x;
    rep(i,1,n) cin >> a[i].ff, a[i].ss = i;
    sort(a+1, a+1+n);
    rep(i,1,n)
    {
        int j = lower_bound(a+i+1, a+1+n, make_pair(x-a[i].ff, 0LL)) - a;
        if (j<=n && a[i].ff + a[j].ff == x)
        {
            cout << a[i].ss << ' ' << a[j].ss << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}