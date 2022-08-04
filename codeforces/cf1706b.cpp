#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int t, n, a[N], nd[N], ans[N];

signed main()
{
    lyx_my_wife
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i], nd[i] = ans[i] = 0;
        
        int nd_all = 0;
        rep(i,1,n)
        {
            if (ans[a[i]] == 0)
                nd[a[i]] = -nd_all;
            if ((nd[a[i]]+nd_all)%2 == 0)
                ans[a[i]]++, nd[a[i]]--;
            nd_all++;
        }
        rep(i,1,n) cout << ans[i] << ' ';
        cout << '\n';
    }
}
/*
6
7
1 2 3 1 2 3 1
6
4 2 2 2 4 4
1
1
5
5 4 5 3 5
6
3 3 3 1 3 3
8
1 2 3 4 4 3 2 1

*/