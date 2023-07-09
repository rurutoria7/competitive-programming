#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define hsiao_8888 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, V = 1e6+10;

int n, a[N], cnt[V], mndiv[V];

void shai()
{
    for (int i=2; i<V; i++)
    {
        if (mndiv[i]) continue;
        mndiv[i] = i;
        for (int j=i*i; j<V; j+=i)
            if (!mndiv[j]) mndiv[j] = i;
    }
}

signed main()
{
    hsiao_8888
    shai();
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    rep(i,1,n)
    {
        if (a[i] == 1) continue;
        vector<int> dv;
        for (int x=a[i]; x>1; x/=mndiv[x])
        {
            if (dv.empty() || mndiv[x] != dv.back())
                dv.pb(mndiv[x]);
        }
        for (int j=1; j<(1<<dv.size()); j++)
        {
            int ouo = (__builtin_popcount(j)%2? 1:-1), owo = 1;
            for (int k=0; k<dv.size(); k++)
            {
                if (j&(1<<k))
                {
                    owo *= dv[k];
                }
            }
            ans += cnt[owo]*ouo;
        }
        for (int j=1; j<(1<<dv.size()); j++)
        {
            int owo = 1;
            for (int k=0; k<dv.size(); k++)
            {
                if (j&(1<<k))
                {
                    owo *= dv[k];
                }
            }
            cnt[owo]++;
        }
    }
    cout << n*(n-1)/2 - ans << '\n';
}

/*
gcd != 1:
    at most 8
    a: 2*3*11*41*91
    b: 2*3*5*11*7
    
    count 2 + count 3 + count 11 + count 41 - count 2*3 - 
    2^8
*/