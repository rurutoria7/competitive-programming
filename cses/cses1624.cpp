#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

typedef bitset<10> B;
B block[10];

int f (B l=B(0), B r=B(0), B v=B(0), int i=1)
{
    if (i >= 9) return 1;
    B cango = (l|r|v|block[i]).flip();
    int pos = 0, res = 0;
    for (pos=cango._Find_first(); pos<=8; pos=cango._Find_next(pos))
    {
        if (pos<1) continue;
        res += f(B(l).set(pos)<<1,B(r).set(pos)>>1,B(v).set(pos),i+1);
    }
    return res;
}

signed main()
{
    rep(i,1,8)
    {
        rep(j,1,8)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                block[i].set(j);
            }
        }
    }
    cout << f() << '\n';
}   