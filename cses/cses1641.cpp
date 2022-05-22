#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define rr7 sync_with_stdio(0), cin.tie(0);
using namespace std;
const int N = 5010;

int n, x;
pair<int,int> a[N];

signed main()
{   
    cin >> n >> x;
    for (int i=1; i<=n; i++)
        cin >> a[i].ff, a[i].ss = i;
    sort(a+1,a+1+n);

    for (int i=1; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (x - a[i].ff - a[j].ff <= 0)
                break;
            int k = lower_bound(a+j+1, a+n+1, make_pair(x-a[i].ff-a[j].ff,0LL))-a;
            if (k != n+1 && a[k].ff == x-a[i].ff - a[j].ff)
            {
                cout << a[i].ss << ' ' << a[j].ss << ' ' << a[k].ss << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}