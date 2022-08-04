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

const int N = 2e5+10;

int t, n, k, a[N];

int check(long long x)
{
    priority_queue<int, vector<int>, greater<int>> tokill;
    rep(i,1,k) tokill.push(a[i]);
    int ntokill = k+1;

    while (tokill.size())
    {
        if (tokill.top() > x)
        {
            return 0;
        }
        else
        {
            x += tokill.top();
            tokill.pop();
            if (ntokill <= n)
            {
                tokill.push(a[ntokill++]);
            }
        }
    }
    return 1;
}

int bs()
{
    long long i = 0, s = 1e9;
    while (s)
    {
        if (i+s > 1e9 or check(i+s))
            s >>= 1;
        else
            i += s;
    }
    return i+1;
}

signed main()
{
    lyx_my_wife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> a[i];
        cout << bs() << '\n';
    }
}
/*
a1, ..., an

every time kill min in a1~ak

if there is no monster to kill
then fail

set of size k, monster to kill
every time kill min
and put next in
*/