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

int t, n;
vector<pii> cnt;

vector<vector<int>> ans;
vector<pii> path;
void dfs(int i, int j) // choose from ith number to nth number, s.t. sum == j
{
    if (j == 0)
    {
        ans.pb({});
        for (auto x: path)
        {
            rep(k,1,x.ss) ans.back().pb(x.ff);
        }
        return;
    }
    if (j < 0) return;
    if (i >= cnt.size()) return;
    for (int x=cnt[i].ss; x>=0; x--)
    {
        path.pb({cnt[i].ff, x});
        dfs(i+1, j-x*cnt[i].ff);
        path.pop_back();
    }
}

signed main()
{
    lyx
    while (cin >> t >> n, t&&n)
    {
        cnt.clear();
        ans.clear();
        path.clear();

        int last = 1e18, c = 0, x;
        rep(i,1,n)
        {
            cin >> x;
            if (x != last)
            {
                cnt.pb({last, c});
                c = 0;
            }
            c++;
            last = x;
        }
        cnt.pb({last, c});

        dfs(0, t);

        cout << "Sums of " << t << ":\n";
        if (ans.size())
        {
            for (auto v: ans)
            {
                for (int i=0; i<v.size(); i++)
                {
                    cout << v[i] << "\n+"[i+1<v.size()];
                }
            }
        }
        else
        {
            cout << "NONE\n";
        }
    }
}