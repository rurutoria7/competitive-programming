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

const int N = 2e5+10;

int n, q, a[N];

struct Seg
{
    int tr[N<<1];
    inline void add(int p, int x)
    {
        for (tr[p+=n]+=x; p>1; p>>=1)
            tr[p>>1] = tr[p]+tr[p^1];
    }
    inline int query(int l, int r)
    {
        int res = 0;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) res += tr[l++];
            if (r&1) res += tr[--r];
        }
        return res;
    }
} st;

signed main()
{
    //mothersrosario
    
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i];

    while(q--)
    {
        int opr, u, v, w;
        cin >> opr;

        if (opr == 1)
        {
            cin >> u >> v >> w;
            u--;
            st.add(u,w); //0
            if (v<n) st.add(v,-w); //4
        }
        else
        {
            cin >> u;
            cout << st.query(0,u)+a[u-1] << '\n';
        }
    }

}

/*
4 100
0 0 0 0
1 1 3 -1
2 1
2 2
2 3
2 4
1 1 4 -1
*/