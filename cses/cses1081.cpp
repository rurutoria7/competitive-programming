#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10, X = 1e6+10;

int n, a[N], divby[X];

signed main()
{
    mothersrosario
    cin >> n;
    rep(i,1,n) cin >> a[i];

    int ans = 0;

    rep(i,1,n)
    {
        for (int j=1; j*j<=a[i]; j++)
        {
            if (a[i]%j == 0)
            {
                divby[j]++;
                if (j != a[i]/j) divby[a[i]/j]++;
                if (divby[j]>1) ans = max(ans, j);
                if (divby[a[i]/j]>1) ans = max(ans, a[i]/j);
            }
        }
    }

    cout << ans << '\n';
}