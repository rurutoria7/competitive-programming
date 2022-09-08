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

const int N = 25;

int n, a[N];

signed main()
{
    cin >> n;
    rep(i,0,n-1) cin >> a[i];
    
    int ans = 0;
    for (int s=0; s<(1<<n); s++)
    {
        int res = 0;
        for (int j=0; j<n; j++)
        {
            if (s&(1<<j))
            {
                res |= a[j];
            }
        }
        ans += res;
    }
    cout << ans << endl;
}