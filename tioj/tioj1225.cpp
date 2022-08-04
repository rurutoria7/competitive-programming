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

const int N = 1e6+10;

int n;
vector<int> st;

signed main()
{
    lyx_my_wife
    cin >> n;
    st.pb(2e9);
    int ans = 0, a;
    rep(i,1,n)
    {
        cin >> a;
        while (st.back()<=a)
        {
            ans += min(st[st.size()-2], a);
            st.pop_back();
        }
        st.pb(a);
    }
    for (int i=1; i<st.size()-1; i++)
        ans += st[i];
    cout << ans << '\n';
}