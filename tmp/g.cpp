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
const int N = 3e5+10;

vector<pair<pii,int>> xseg, yseg;

int t, n, l[N], r[N], d[N], u[N], w[N];

int solve (vector<pair<pii, int>> seg)
{
    int ans = -1;
    map<int,int> mp; // left better, w bigger better
    sort(seg.begin(), seg.end());
    for (int i=seg.size()-1; i>=0; i--)
    {   
        int ll = seg[i].ff.ff, rr = seg[i].ff.ss, ww = seg[i].ss;

        auto upb = mp.upper_bound(rr);
        if (upb != mp.end())
            ans = max(ans, upb->ss+ww);

        auto owo = mp.insert({ll,ww}).ff;
        while (prev(owo) != mp.begin() && prev(owo)->ss <= ww)
        {
            mp.erase(prev(owo));
        }
        for (auto p: mp) de(p.ff), de(p.ss), dd
        dd
    }
    return ans;
}

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> l[i] >> d[i] >> r[i] >> u[i];
        rep(i,1,n) cin >> w[i];
        xseg.clear(), yseg.clear();
        rep(i,1,n)
            xseg.pb({{l[i], r[i]}, w[i]}), yseg.pb({{d[i], u[i]}, w[i]});
        cout << max(solve(xseg), solve(yseg)) << endl;
    }
}
/*
10 
4
0 0 2 3
2 1 4 5
3 3 5 6
4 6 6 8 
2 3 3 3
*/