#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

rbtree tr;
int n;

signed main()
{
    a_little_luckier
    cin >> n;
    rep(i,1,n)
    {
        int x;
        cin >> x;
        tr.insert({x,i});
        cout << tr.find_by_order((i-1)/2)->ff << ' ';
    }
    cout << '\n';
}

