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

const int N = 1e5+10, A = 2e5+10;

int n, a[N];
vector<int> cnt_colle[A];

int qpow (int i, int j)
{
    int res = 1;
    for (int x=i; j; j>>=1,x*=x)
        if (j&1)
            res *= x;
    return res;
}

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> a[i];

    rep(i,1,n)
    {
        int x = a[i];
        for (int j=2; j*j<=a[i]; j++)
        {
            int cnt = 0;
            while (x%j==0) cnt++, x/=j; 
            if (cnt > 0) cnt_colle[j].pb(cnt);
        }
        if (x>1) cnt_colle[x].pb(1);
    }

    int ans = 1;
    rep(i,2,A-1)
    {
        if (cnt_colle[i].size() >= n-1)
        {
            sort(cnt_colle[i].begin(), cnt_colle[i].end());
            ans *= qpow(i, cnt_colle[i][cnt_colle[i].size() == n-1? 0:1]);
        }
    }
    cout << ans << '\n';
}

//for every primes, get second min cnt
//cnt[i]: all cnt
//max(cnt[i][j] > 0), i must be prime