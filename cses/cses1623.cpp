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

const int N = 22;

int n, a[N], sum, ans = 9e18;

signed main()
{
    cin >> n;
    rep(i,0,n-1) cin >> a[i], sum += a[i];
    for (int i=0; i<(1<<n); i++)
    {
        int owo = 0;
        for (int j=0; j<n; j++)
        {
            if (i&(1<<j))
            {
                owo += a[j];
            }
        }
        ans = min(ans, abs(sum - owo - owo));
    }
    cout << ans << '\n';
}
//sum - 