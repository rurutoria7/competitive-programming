#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define las(x) (prev((x).end()))
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int n;
pair<pii,int> a[N]; //{l,r}, w
map<int,int> src; //r, dp

signed main()
{
    cin >> n;
    rep(i,1,n)
        cin >> a[i].ff.ff >> a[i].ff.ss >> a[i].ss;
    sort(a+1,a+1+n);
    rep(i,1,n)
    {
        pii nw;//r, dp
        int l = a[i].ff.ff, r = a[i].ff.ss, w = a[i].ss, dp;
        if (src.empty() || l <= src.begin()->ff)
            dp = w;
        else
            dp = prev(src.lower_bound(l))->ss+w;
        if (src.size() && r >= las(src)->ff)
        {
            if (las(src)->ss < dp)
                src[r] = dp;
        }
        else if (src.empty() || r < src.begin()->ff || prev(src.upper_bound(r))->ss < dp)
        {
            while (src.size() && r<=las(src)->ff && dp>=src.lower_bound(r)->ss)
                src.erase(src.lower_bound(r));
            src[r] = dp;
        }
    }
    cout << las(src)->ss << '\n';
}