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
#define rr7 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int N = 1010;

int n, x, a[N], id[N];

int cmp (int i, int j)
{
    return a[i]<a[j];
}

signed main()
{
    rr7
    cin >> n >> x;
    for (int i=1; i<=n; i++)
        cin >> a[i], id[i] = i;

    sort (id+1, id+1+n, cmp);
    if (n >= 4)
    {
        a[0] = x - a[id[n]] - a[id[n-1]] - a[id[n-2]];
        for (int i=lower_bound(id+1,id+n-2,0,cmp)-id; i+3<=n; i++)
        {
            if (a[id[i]]+a[id[i+1]]+a[id[i+2]]+a[id[i+3]] > x)
                break;
            a[0] = x - a[id[i]] - a[id[n]] - a[id[n-1]];
            for (int j=lower_bound(id+i+1,id+n-1,0,cmp)-id; j+2<=n; j++)
            {
                if (a[id[i]]+a[id[j]]+a[id[j+1]]+a[id[j+2]] > x)
                    break;
                a[0] = x - a[id[i]] - a[id[j]] - a[id[n]];
                for (int k=lower_bound(id+j+1,id+n-2,0,cmp)-id; k+1<=n; k++)
                {
                    if (a[id[i]]+a[id[j]]+a[id[k]]+a[id[k+1]] > x)
                        break;
                    a[0] = x - a[id[i]] - a[id[j]] - a[id[k]];
                    int l = lower_bound(id+k+1,id+n+1,0,cmp)-id;
                    if (l<=n && a[id[l]]==a[0])
                    {
                        cout << id[i] << ' ' << id[j] << ' ' << id[k] << ' ' << id[l] << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}