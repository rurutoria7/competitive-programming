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

vector<pii> ans;
int n;

void f (int i, int a, int b, int c)
{
    if (i == 1)
    {
        ans.pb({a,c});
    }
    else
    {
        f(i-1,a,c,b);
        ans.pb({a,c});
        f(i-1,b,a,c);
    }
}

signed main()
{
    cin >> n;
    f(n,1,2,3);
    cout << ans.size() << '\n';
    for (auto x: ans)
    {
        cout << x.ff << ' ' << x.ss << '\n';
    }
}