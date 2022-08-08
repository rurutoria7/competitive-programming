#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 10;

int n, a[N], t;

signed main()
{
    lyx_my_wife
    cin >> t;
    while (t--)
    {
        rep(i,1,7) cin >> a[i];

        int flag = 0;
        
        rep(i,1,6)
        {
            if (a[i] < a[i+1])
            {
                flag = 1;
            }
        }

        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            int ans = 0, j = 1;
            rep(i,1,7) if (a[i] > 0) j = i;        
            while (a[j] > 0)
            {
                rep(i,1,7)
                {
                    if (a[i] > a[j])
                        a[i] -= (a[j]+1);
                    else
                        a[i] -= a[j];
                }
                rep(i,1,7) if (a[i] > 0) j = i;
                ans += 1;
            }
            cout << ans << endl;
        }
    }
}