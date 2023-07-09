#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define a_little_luckier ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e6+10;

int n, k; 

struct Seg
{
    int tr[N<<1];
    void build()
    {
        for (int i=n-1; i>0; i--) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }
    int query(int l, int r)
    {
        int ans = -2e9;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {  
            if (l&1) ans = max(ans, tr[l++]);
            if (r&1) ans = max(ans, tr[--r]);
        }
        return ans;
    }
} seg;

signed main()
{
    a_little_luckier
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> seg.tr[i+n];
    seg.build();
    for (int l=0,r=k; l<n; l++,r=(r+1)%n)
    {
        if (l<r) cout << seg.query(l,r) << ' ';
        else cout << max(seg.query(l,n), seg.query(0,r)) << ' ';
    }
    cout << '\n';
}