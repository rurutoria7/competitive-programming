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

vector<char> st;
string s;
int ans;

signed main()
{
    cin >> s;
    for (auto c: s)
    {
        if (st.size() && st.back()=='S' && c == 'T')
            st.pop_back(), ans++;
        else
            st.pb(c);
    }
    cout << st.size() << '\n';
}