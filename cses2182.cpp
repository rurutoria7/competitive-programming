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

const int M = 1e9+7, N = 1e5+10;

int n;
pii pk[N];
int num[N], num2[N], sum[N], prod[N];

inline int qpow (int i, int j)
{
    int res = 1;
    for (int x=i; j; j>>=1,x=x*x%M)
        if (j&1)
            res = res*x%M;
    return res;
}

signed main()
{
    mothersrosario
    cin >> n;
    rep(i,1,n) cin >> pk[i].ff >> pk[i].ss; //p^k, p: ff, k: ss

    //num
    num[n+1] = num2[n+1] = 1;
    for (int i=n; i>0; i--)
    {
        num[i] = num[i+1]*(pk[i].ss+1)%M;
        num2[i] = num2[i+1]*(pk[i].ss+1)%(M-1);
    }

    //sum
    sum[n+1] = 1;
    for (int i=n; i>0; i--)
    {
        sum[i] = sum[i+1] * (qpow(pk[i].ff, pk[i].ss+1)-1+M)%M * qpow(pk[i].ff-1,M-2)%M;
    }

    //prod
    prod[n+1] = 1;
    for (int i=n; i>0; i--)
    {
        prod[i] = qpow( pk[i].ff, (1+pk[i].ss)*pk[i].ss/2%(M-1)*num2[i+1]%(M-1) ) * qpow(prod[i+1],pk[i].ss+1)%M;
    }


    cout << num[1] << ' ' << sum[1] << ' ' << prod[1] << '\n';
}