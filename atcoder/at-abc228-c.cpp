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

const int N = 1e5+10;

int n, k, pre[1210], a[N];

signed main()
{
    cin >> n >> k;
    rep(i,1,n)
    {
        int x;
        rep(j,1,3) cin >> x, a[i] += x;
        pre[a[i]]++;
    }
    rep(i,0,1200) pre[i] += pre[i-1];
    rep(i,1,n) cout << (pre[1200] - pre[a[i]+300] < k? "Yes":"No") << '\n';
}
