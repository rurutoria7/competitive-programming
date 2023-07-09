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

const int N = 2e5+10;

int t, q, n;

struct Linked
{  
    int np[N], pp[N]; 
    void init(int n)
    {
        rep(i,0,n) np[i] = i+1, pp[i+1] = i;
    }
    void rem(int i)
    {
        np[pp[i]] = np[i];
        pp[np[i]] = pp[i];
    }
    void ins(int i, int to)
    {
        np[i] = np[to];
        pp[i] = to;
        pp[np[to]] = i;
        np[to] = i;
    }
    void print()
    {
        for (int i=np[0]; i<=n; i=np[i]) cout << i << ' ';
        cout << '\n';
    }
} l;

signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        l.init(n);
        while (q--)
        {
            char opr;
            int i;
            cin >> opr >> i;
            if (opr == 'H') l.rem(i), l.ins(i, 0);
            else l.rem(i), l.ins(i, l.pp[n+1]);
        }
        l.print();
    }
}
/*
1
5 3
H 4
T 2
H 5

1
10 8
H 1
T 4
T 7
H 3
H 4
T 10
T 1
H 3
*/