#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define lowbit(i) (i&(-i))
using namespace std;
typedef pair<int,int> pii;

const int N = 3010;

int tr[N][N], n, m, q;

int query(int r, int c)
{
    int res = 0;
    for (int i=r; i; i-=lowbit(i))
        for (int j=c; j; j-=lowbit(j))
            res += tr[i][j];
    return res;
}
int qsum (int u, int d, int l, int r)
{
    return query(d,r) - query(u-1,r) - query(d,l-1) + query(u-1,l-1);
}
void add(int r, int c, int x)
{
    for (int i=r; i<=n; i+=lowbit(i))
        for (int j=c; j<=m; j+=lowbit(j))
            tr[i][j] += x;
}

signed main()
{
    lyx_my_wife
    cin >> n >> m;
    rep(i,1,n)
    {
        rep(j,1,m)
        {
            int k;
            cin >> k;
            change(i,j,k);
        }
    }
    cin >> q;
    while (q--)
    {
        char c;
        int x, y, z, w;
        cin >> c;
        if (c == 'C')
        {
            cin >> x >> y >> z;
            change(x,y,z);
        }
        else
        {
            cin >> x >> y >> z >> w;
            cout << qsum(x,z,y,w) << '\n';
        }
    }
}
