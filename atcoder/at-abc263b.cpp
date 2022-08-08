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

const int N = 1000;

int n, p[N];

signed main()
{
    cin >> n;
    rep(i,2,n) cin >> p[i];

    int ans = 0;
    for (int i=n; i>1; i=p[i]) ans++;
    cout << ans << endl;
}