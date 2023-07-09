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

multiset<int> sorted;
deque<int> st;
int q;

signed main()
{
    a_little_luckier
    cin >> q;
    while (q--)
    {
        int opr, x;
        cin >> opr;
        if (opr == 1)
        {
            cin >> x;
            st.pb(x);
        }
        if (opr == 2)
        {
            if (sorted.size())
            {
                cout << *sorted.begin() << '\n';
                sorted.erase(sorted.begin());
            }
            else   
            {
                cout << st.front() << '\n';
                st.pop_front();
            }
        }
        if (opr == 3)
        {
            while(st.size())
            {
                sorted.insert(st.front());
                st.pop_front();
            }
        }
    }
}