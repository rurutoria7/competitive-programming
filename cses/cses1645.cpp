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

const int N = 2e5+10;

vector<int> st;
int n, a[N];

signed main()
{
    a_little_luckier
    cin >> n;
    rep(i,1,n) cin >> a[i];
    st.pb(0);
    rep(i,1,n)
    {
        while (st.back()[a]>=a[i]) st.pop_back();
        cout << st.back() << ' ';
        st.pb(i);
    }
    cout << '\n';
}

/*
{x, id}
id greater, x larger
*/