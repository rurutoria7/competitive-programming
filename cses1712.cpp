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

const int M = 1e9+7;

int qpow (int i, int j, int k)
{
    int res = 1;
    for (int x=i; j; j>>=1,x=x*x%k)
        if (j&1)
            res = res*x%k;
    return res;
}

signed main()
{
    mothersrosario
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << qpow(a,qpow(b, c, M-1),M) << '\n';
    }
}