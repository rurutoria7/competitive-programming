#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

vector<int> path;
int n, m;
void dfs (int i, int j)
{
    if (i == n+1)
    {
        for (auto x: path) cout << x << ' ';
        cout << endl;
    }
    rep(v, j, m)
    {
        path.pb(v);
        dfs(i+1, v+1);
        path.pop_back();
    }
}

signed main()
{
    cin >> n >> m;
    dfs(1, 1);
}