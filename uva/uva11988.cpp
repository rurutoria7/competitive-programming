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

vector<string> fb[2];
string s;

signed main()
{
    while (cin >> s)
    {
        fb[0].clear();
        fb[1].clear();
        int fob = 0;
        string cur;
        for (int i=0; i<=s.size(); i++)
        {
            if (s[i] == '[' || s[i] == ']' || i == s.size())
            {
                fb[fob].pb(cur);
                if (s[i] == '[') fob = 0;
                if (s[i] == ']') fob = 1;
                cur = "";
            }
            else
            {
                cur += s[i];
            }
        }
        for (int i=fb[0].size()-1; i>=0; i--) cout << fb[0][i];
        for (int i=0; i<fb[1].size(); i++) cout << fb[1][i];
        cout << '\n';
    }
}