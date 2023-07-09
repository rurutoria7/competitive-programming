#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define hsiao_8888 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10;

int T, n, a[N], rest[N], fa[N];
pii ans[N];
vector<pii> st;
vector<int> st2;

signed main()
{
    hsiao_8888
    cin >> T;
    while (T--)
    {
        cin >> n;

        rep(i,0,n) ans[i] = {-9e18,0};
        st.clear();
        st2.clear();

        rep(i,1,n) cin >> a[i], a[i] += a[i-1];
        a[n+1] = -9e18;
        rep(i,0,n+1)
        {
            pii ppr = {i, 1}; 
            while (st.size() && st.back().ff[a] > ppr.ff[a])
            {
                rest[st.back().ff] = st.back().ff + ppr.ss - 1;
                ppr.ss += st.back().ss;
                st.pop_back();
            }
            st.pb(ppr);
        }
        st2.pb(n+1), rest[n+1] = 9e18;
        rep(ppr,0,n)
        {
            while (st2.size() && st2.back()[rest] < ppr[rest])
            {
                st2.pop_back();
            }
            fa[ppr] = st2.back();
            while (st2.size() && st2.back()[rest] <= ppr[rest])
                st2.pop_back();
            st2.pb(ppr);
        }
        int res = 0;
        for (int i=n; i>=0; i--)
        {
            ans[i] = max(ans[i], {a[i], i});
            ans[fa[i]] = max(ans[fa[i]], ans[i]);
            res = max(res, ans[i].ss-i);
        }
        cout << res << '\n';
        //rep(i,0,n) de(i), de(a[i]), de(rest[i]), de(fa[i]), de(ans[i].ff), de(ans[i].ss), dd
        //dd
    }
}
/*
1
10 
3 4 8 -7 6 -3 1 -7 2 9
*/