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

const int N = 30;

int vis[N], t, n, a[N], sum;

int dfs (int i, int req, int num, int remain) // choose from i~n, comb req, remain num req to comb in total
{
    if (num == 0) return 1;
    if (req == 0)
    {
        remain = 0;
        rep(i,1,n) if (!vis[i]) remain += a[i];
        return dfs(1, sum/4, num-1, remain);
    }
    if (remain < req) return 0;
    if (dfs(i+1, req, num, remain-a[i]*(!vis[i]))) return 1;
    if (!vis[i] && req >= a[i])
    {
        vis[i] = 1;
        int res = dfs(i+1, req-a[i], num, remain-a[i]);
        vis[i] = 0;
        if (res) return 1;
    }
    return 0;
}

signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        rep(i,1,n) cin >> a[i], sum += a[i];

        sort(a+1, a+1+n, [](int x, int y){ return x > y; });
        
        if (sum%4) cout << "no\n";
        else if (dfs(1, sum/4, 4, sum)) cout << "yes\n";
        else cout << "no\n";
    }
}