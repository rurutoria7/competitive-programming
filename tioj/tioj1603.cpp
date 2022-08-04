#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10, L = __lg(N)+1;

int n, q, a[N];

struct SparseTable
{
    int tmn[L][N], tmx[L][N];
    void build()
    {
        rep(i,1,n) tmn[0][i] = tmx[0][i] = a[i];
        for (int k=1; (1<<k)<=n; k++)
        {
            for (int i=1,l=(1<<k); i+l-1<=n; i++)
            {
                tmn[k][i] = min(tmn[k-1][i], tmn[k-1][i+(l/2)]);
                tmx[k][i] = max(tmx[k-1][i], tmx[k-1][i+(l/2)]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = __lg(r-l+1), len = (1<<k);
        return max(tmx[k][l],tmx[k][r-len+1]) - min(tmn[k][l],tmn[k][r-len+1]);
    }
} st;

signed main()
{
    lyx_my_wife
    cin >> n >> q;
    rep(i,1,n) cin >> a[i];

    st.build();

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l,r) << '\n';
    }
}