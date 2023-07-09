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

const int N = 1e6+10;

int n, m;

struct Linked
{
    int pv[N*3], nx[N*3];
    
    void init()
    {
        rep(i,1,n) i[nx] = i+n, (i+n)[pv] = i, (i+n)[nx] = i+2*n, (i+2*n)[pv] = i+n;
    }
    void move_all(int x, int y) // move all in queue x to queue y
    {
        if (x[nx] == (x+2*n)) return;
        int h = x[nx], t = (x+2*n)[pv], h2 = (y+2*n)[pv];
        h2[nx] = h, h[pv] = h2;
        t[nx] = y+2*n, (y+2*n)[pv] = t;
        x[nx] = x+2*n, (x+2*n)[pv] = x;
    }
    void remove(int x)
    {
        x[pv][nx] = x[nx];
        x[nx][pv] = x[pv];
    }
    void insert(int x, int y) // insert y after x
    {
        int h = x, t = x[nx];
        h[nx] = y, y[pv] = h;
        y[nx] = t, t[pv] = y;
    }
    void print(int x)
    {
        for (int i=x[nx]; i!=x+2*n; i=i[nx]) cout << ' ' << i-n;
    }
} l;

signed main()
{
    lyx
    cin >> n >> m;
    l.init();
    while (m--)
    {
        int opr, x, y;
        cin >> opr >> x >> y;
        
        if (opr == 0)
        {
            l.remove(x+n);
            l.insert(y+n, x+n);
        }
        if (opr == 1)
        {
            l.move_all(x,y);
        }  
    }
    rep(i,1,n)
    {
        cout << "#" << i << ":";
        l.print(i);
        cout << '\n';
    }
}