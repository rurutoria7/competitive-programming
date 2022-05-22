#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10;

int n, a[N];

signed main()
{
    int k = 0;
    cin >> n;
    rep(i,1,n) cin >> a[i], k += a[i];
    rep(i,1,n) a[i] += a[i-1];

    if (k%3)
    {
        cout << 0 << '\n';
        return 0;
    }
    else
    {
        k /= 3;
    }

    int ans = 0;
    map<int,int> cnt;
    for (int i=n; i>0; i--)
    {
        if (a[i] == k) ans += cnt[a[i]+k];
        if (i!=n) cnt[a[i]]++;
    }
    cout << ans << '\n';
}