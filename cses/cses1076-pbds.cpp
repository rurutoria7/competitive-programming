#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update
> trii;

const int N = 2e5+10;

int a[N], n, k;
trii tr;

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
    {
        tr.insert({a[i],i});
        if (i > k)
            tr.erase(tr.lower_bound({a[i-k],0}));
        if (i>=k)
            cout << tr.find_by_order((k-1)/2)->ff << "\n "[i+1<=n];
    }
}