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

const int N = 2010;

int t, n, mx[N], sum[N], id[N];
vector<int> ep[N];

int cmp (int i, int j)
{
    if (sum[i] != sum[j]) return sum[i] > sum[j];
    if (mx[i] != mx[j]) return mx[i] > mx[j];
    if (ep[i].size() != ep[j].size()) return ep[i].size() > ep[j].size();
    return i < j;
}

signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> n;

        memset(mx, 0, sizeof(mx));
        memset(sum, 0, sizeof(sum));
        rep(i,1,n) ep[i].clear();

        rep(i,1,n)
        {
            int m, x;
            cin >> m;
            rep(j,1,m) cin >> x, ep[i].pb(x), mx[i] = max(mx[i], x), sum[i] += x;
        }
        rep(i,1,n) id[i] = i;
        sort(id+1, id+1+n, cmp);
        rep(i,1,n)
        {
            for (auto x: ep[id[i]]) cout << x << ' ';
            cout << '\n';
        }
    }
}