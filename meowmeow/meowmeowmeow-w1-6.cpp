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

int n, t;
int px[N], py[N], pw[N];

vector<int> path, ans;
int best;

void dfs(int p, int toc)
{
    if (p == 25)
    {
        int sum = 0;
        rep(i,1,n)
        {
            int dis = 1e18;
            for (auto x: path)
            {
                int r = x/5, c = x%5;
                dis = min(dis, abs(r-px[i])+abs(c-py[i]));
            }
            sum += dis*pw[i];
        }
        if (sum < best)
        {
            ans = path;
            best = sum;
        }
        return;
    }
    if (toc)
    {
        path.pb(p);
        dfs(p+1, toc-1);
        path.pop_back();
    }
    if (25-p > toc)
    {
        dfs(p+1, toc);
    }
}

signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> n;
        best = 1e18;
        path.clear();
        rep(i,1,n) cin >> px[i] >> py[i] >> pw[i];
        dfs(0, 5);
        for (auto x: ans) cout << x << ' ';
        cout << '\n';
    }
}