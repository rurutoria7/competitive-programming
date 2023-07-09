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

const int N = 30;

int n, m, a[N];

vector<int> path;
void comb (int st, int chs)
{
    if (st > n)
    {
        for (auto x: path) cout << x << ' ' ;
        cout << '\n';
        return;
    }
    if (chs > 0)
    {
        path.pb(a[st]);
        comb(st+1, chs-1);
        path.pop_back();
    }
    if (n-st+1>chs)
        comb(st+1, chs);
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    comb(1,m);
}