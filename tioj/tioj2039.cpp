#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 2e6+10, V = 15e8+10;

int n, k, a[N];

//get most left extrenum
pii dp0[N], dp1[N]; //{value, -buy cnt}
pii maximum (int p)
{
    dp1[1] = {-a[1]-p,-1};
    dp0[1] = {0,0};
    rep(i,2,n)
    {
        dp1[i] = max(dp1[i-1], {dp0[i-1].ff-a[i]-p, dp0[i-1].ss-1});
        dp0[i] = max(dp0[i-1], {dp1[i-1].ff+a[i], dp1[i-1].ss});
    }
    return {-dp0[n].ss, dp0[n].ff};
}

int bs()
{
    int i = 0, s = V;
    while (s)
    {
        if (i+s>V || maximum(i+s).ff<=k)
            s >>= 1;
        else
            i += s;
    }
    return i+1;
}

int aliens ()
{
    pii q = maximum(0);
    if (q.ff <= k) return q.ss;
    int p = bs();
    return maximum(p).ss + p*k;
}

signed main()
{
    liyuu_my_wife
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    cout << aliens() << '\n';
}