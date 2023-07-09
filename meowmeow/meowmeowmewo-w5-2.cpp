#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define a_little_luckier ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;
vector<pii> st;

int n, a[N];

signed main()
{
    a_little_luckier
    while (cin >> n)
    {
        rep(i,1,n) cin >> a[i];

        int ans = 0;
        rep(i,1,n+1)
        {
            int j = i;
            while (st.size() && st.back().ff >= a[i])
            {
                ans = max(ans, st.back().ff*(i-st.back().ss));
                j = st.back().ss;
                st.pop_back();
            }
            st.pb({a[i], j});
        }
        cout << ans << '\n';
    }
}