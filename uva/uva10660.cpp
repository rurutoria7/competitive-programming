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

const int N = 5;

int t, n;
vector<pair<pii, int>> p;
vector<int> path, ans;
int ans, owo;

void dfs (int num, int st)
{
    if (num == 0)
    {
        
    }
}

signed main()
{
    cin >> t;
    while(t--)
    {
        p.clear();
        cin >> n;
        rep(i,1,n)
        {
            int x, y, z;
            p.pb({{x,y},z});
        }
        dfs(5, 0);
    }
}