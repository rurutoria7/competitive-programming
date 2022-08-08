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
const int N = 1e5+10;

/*
split a1...an to minimal number of pieces, s.t.:
each pieces contains at least l number : len greater, better
max and min in each pieces at most s : len greater, worse

dp[i]: minimal number to split 1~i into pieces

dp[i] = 1 + min(dp[i-len], l <= len <= i, dif[i-len+1,i] <= s) 
dp[0] = 0

binary search on dif[i]

min seg, max seg, binary search, point update

rep(i,1,n)
    // this section len in [mx_len, l]
    // this section's left in [i-mx_len+1, i-l+1]
    // next section end in [i-mx_len, i-l]

    mx_len = dif.bs(i) for max len s.t. dif[i-len+1,i] <= s
    d = dp.query_min(i-len, i-l)
*/

int n, s, l, a[N];

struct Node
{
    int mn, mx;
};
struct Seg 
{
    int L, R;
    Node tr[N<<2];
    void build_by_arr(int arr[], int u=1, int l=L, int r=R) // build from arr
    {

    }
    void build_by_fill(int x, int u=1, int l=L, int r=R)
    {

    }
    Node merge(Node i, Node j)
    {

    }
    void update(int i, int x, int u=1, int l=L, int r=R)
    {

    }
    int bs(int qr) // find max len s.t. dif[qr-len+1, qr] <= s
    {

    }
    Node query(int ql, int qr, int u=1, int l=L, int r=R)
    {

    }
} dif, dp;

signed main()
{
    cin >> n >> s >> l;
    rep(i,1,n) cin >> a[i];

    dif.L = 1, dif.R = n, dif.build_by_arr(a);
    dp.L = 0, dp.R = n, dp.build_by_fill(1e9);
    dp.update(0,0);

    rep(i,1,n)
    {
        int mx_len = dif.bs(i);
        int d = dp.query(i-mx_len, i-l).mn + 1;
        if (i == n) return cout << d << '\n', 0;
        else dp.update(i,d);
    }
}
