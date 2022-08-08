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

string s;
int t;

signed main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> s;
        int ans = 0;
        for (int i=0; i+2<s.size(); i++)
        {
            if (s[i] != 'y') continue;
            for (int j=i+1; j<s.size() && s[j] == 'b'; j++)
            {
                if (j-i > 1) ans ++ ;
            }
        }
        cout << ans << endl;
    }
}