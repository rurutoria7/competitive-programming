#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife cin.tie(0), ios::sync_with_stdio(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;
int n, k, t, a[N];

signed main()
{
    lyx_my_wife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        
        int mn = 1e18;
        rep(i,1,n) cin >> a[i], mn = min(mn, a[i]);

        if (k == 1)
        {
            int flag = 0;
            rep(i,1,n-1) 
            {
                if (a[i] != a[i+1])
                {
                    cout << -1 << endl;
                    flag = 1;
                }
            }
            if (flag == 0)
                cout << 0 << endl;
        }
        else
        {
            int ans = 0;
            for (int i=1; i<=n; )
            {
                if (a[i] > mn)
                {
                    ans++;
                    int havblack = 0;
                    rep(j,i+1,i+k-1)
                        if (a[j] == mn)
                            havblack = 1;
                    if (havblack)
                        i += k;
                    else    
                        i += k-1;
                }
                else
                {
                    i++;
                }
            }
            cout << ans << endl;
         }
    }
}
/*
3
8 3
1 1 1 1 1 0 1 1
4 4
0 0 1 0
4 4
0 0 0 0

1
8 2
0 1 0 1 0 1 0 1
*/