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

int T, n, m;
pii a, b, c, d;

pii operator - (pii x, pii y) { return {x.ff-y.ff, x.ss-y.ss}; }
pii operator * (pii x, pii y) { return {x.ff*y.ff, x.ss*y.ss}; }

pii intersect(pii x, pii y, pii z, pii w) //return h, w;
{
    int u = min(max(x.ss, y.ss), max(z.ss, w.ss));
    int d = max(min(x.ss, y.ss), min(z.ss, w.ss));
    int l = max(min(x.ff, y.ff), min(z.ff, w.ff));
    int r = min(max(x.ff, y.ff), max(z.ff, w.ff));
    return {r-l+1, u-d+1};
}

signed main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> a.ff >> a.ss >> b.ff >> b.ss >> c.ff >> c.ss >> d.ff >> d.ss;
        pii inter = intersect(a,b,c,d);
        pii fw = (a-b)*(c-d);

        if (inter.ff<=0 || inter.ss<=0) cout << 0 << endl;
        else if (fw.ff * fw.ss > 0) cout << inter.ss+inter.ff-1 << endl;
        else cout << max(inter.ff, inter.ss) << endl;
    }
}
/*
 
2
4 5 1 2 4 4 2 1 3 5
4 5 3 5 2 1 4 4 1 2

1
4 5 3 1 1 3 4 5 1 1

1
4 5 1 1 1 2 4 4 4 5
*/