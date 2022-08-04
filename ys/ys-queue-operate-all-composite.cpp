#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int M = 998244353;

int qpow (int i, int j)
{
    int res = 1;
    for (int x=i; j; j>>=1, x=x*x%M)
        if (j&1) res = res*x%M;
    return res;
}

typedef pii func;
func operator*(func i, func j) { return {i.ff*j.ff%M, (i.ss*j.ff%M + j.ss)%M}; }
func inv(func i) { return {qpow(i.ff,M-2), (-i.ss*qpow(i.ff,M-2)%M+M)%M}; }
int query(func i, int x) { return (i.ff*x%M+i.ss)%M; }

int q;
deque<func> fque;
pii prod = {1,0};


signed main()
{
    mothersrosario
    cin >> q;
    while (q--)
    {
        int opr, c, d;
        cin >> opr;
        
        if (opr == 0 && cin >> c >> d)
        {
            fque.pb({c,d});
            prod = prod*fque.back();
        }
        else if (opr == 1)
        {
            prod = inv(fque.front())*prod;
            fque.pop_front();
        }
        else if (opr == 2 && cin >> c) cout << query(prod, c) << '\n';
    }
}