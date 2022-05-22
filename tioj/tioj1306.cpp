#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int t, q;

struct KMP
{
    string s, p;
    int f[N];
    void build()
    {
        f[0]=-1, f[1]=0;
        for (int i=1,j; i<p.size(); i++)
        {
            for (j=f[i]; j>=0 && p[j]!=p[i]; j=f[j]);
            f[i+1] = j+1;
        }
    }
    int match ()
    {
        int ans = 0;
        for (int i=0,j=0; i<s.size(); i++,j++)
        {
            while (j>=0 && s[i]!=p[j]) j = f[j];
            if (j == p.size()-1) ans++;
        }
        return ans;
    }
} kmp;

signed main()
{
    liyuu_my_wife
    cin >> t;
    while (t--)
    {
        cin >> kmp.s >> q;
        while (q--)
        {
            cin >> kmp.p;
            kmp.build();
            cout << kmp.match() << '\n';
        }
    }
}