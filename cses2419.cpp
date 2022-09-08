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

const int N = 2e5+10;

int n, a[N], ans, power[N];

int need (int i)
{
    int x=n-1, y=i-1;//c(x,y)
    int p = power[x] - power[x-y] - power[y];
    return p == 0;
}

signed main()
{
    lyx
    cin >> n;
    rep(i,1,n) cin >> a[i];

    for (int i=2; i<=n; i*=2)
        for (int j=i; j<=n; j+=i)
            power[j]++;
    rep(i,1,n) power[i] += power[i-1];

    int ans = 0;
    rep(i,1,n)
        if (need(i)) ans ^= a[i];
    
    cout << ans << endl;
}