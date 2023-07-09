#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define low(x) ((x)&(-(x)))
using namespace std;
typedef pair<int,int> pii;

int t, n, m;

int dfs(int vvis, int slvis4q, int srvis4q, int slvis4r, int srvis4r, int rq, int rrk) //vvis, slvis, srvis, rq, rrk
{
    if ((!rq) && (!rrk)) return 1;
    int ans = 0;
    if (rq > 0)
    {
        int canp = ~(vvis|slvis4q|srvis4q);
        for (int i; canp; canp -= i)
        {
            i = low(canp);
            ans += dfs(vvis|i, (slvis4q|i)<<1, (srvis4q|i)>>1, (slvis4r|i)<<1, (srvis4r|i)>>1, rq-1, rrk);
        }
    }
    if (rrk > 0)
    {
        int canp = ~(vvis|slvis4r|srvis4r);
        for (int i; canp; canp -= i)
        {
            i = low(canp);
            ans += dfs(vvis|i, (slvis4q|i)<<1, (srvis4q|i)>>1, (slvis4r)<<1, (srvis4r)>>1, rq, rrk-1);
        }
    }    
    return ans; 
}


signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << dfs(~((1<<(n+m))-1), 0, 0, 0, 0, n, m) << '\n';
    }
}