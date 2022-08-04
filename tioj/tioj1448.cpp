#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 2e6;

int n, k;

struct DSU
{
    int p[N];
    void init()
    {
        for(int i=1; i<=3*n; i++)
            p[i] = i;
    }
    int find(int x) { return (p[x]==x? x:p[x]=find(p[x])); }
    void U(int x, int y) { p[find(x)] = find(y); }
    int same(int x, int y) { return find(x)==find(y); }
} dsu;

void func(){}

signed main()
{
    lyx_my_wife
    cin >> n >> k;
    func();
    dsu.init();

    int ans = 0;
    rep(i,1,k)
    {
        int opr, x, y;
        cin >> opr >> x >> y;
        if (x>n || y>n) ans++;
        else if (opr == 1)
        {
            if (dsu.same(x,y+n) || dsu.same(y,x+n))
                ans++;
            else
                dsu.U(x,y), dsu.U(x+n,y+n), dsu.U(x+2*n, y+2*n);
        }
        else
        {
            if (dsu.same(x,y) || dsu.same(y,x+n))
                ans++;
            else
                dsu.U(x,y+n), dsu.U(x+n,y+2*n), dsu.U(x+2*n,y);
        }
    }
    cout << ans << '\n';
}