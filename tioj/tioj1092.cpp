#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e4+10, M = 1e5+10;

int n, e, dp[N];
vector<int> G[N];

int f(int i)
{
    if (dp[i] < 0)
    {
        if (i == n) dp[i] = 0;
        else
        {
            dp[i] = 0;
            for (auto v: G[i])
            {
                dp[i] |= (f(v) == 0);
            }
        }
    }
    return dp[i];
}

signed main()
{
    lyx_my_wife
    while (cin >> n >> e, n||e)
    {
        rep(i,1,n) dp[i] = -1, G[i].clear();
        rep(i,1,e)
        {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
        }
        string name[2];
        cin >> name[0];
        name[1] = (name[0]=="Mimi"? "Moumou" : "Mimi");

        cout << name[f(1)] << '\n';
    }
}
/*
dp[i]:
當對手站在 i, 自己必勝嗎？
aka 當自己站在 i, 自己必敗嗎？

dp[n] = 0
dp[u] = any dp[v] == 0
*/