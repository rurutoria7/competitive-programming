#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int N = 3e5+10;

int lt[N], rt[N], n, k, q, a[N], t[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        for (int i=1; i<=k; i++)
            cin >> a[i];
        for (int i=1; i<=k; i++)
            cin >> t[i];

        memset(lt,0x3f,sizeof(lt));
        memset(rt,0x3f,sizeof(rt));

        for (int i=1; i<=k; i++)
            lt[a[i]] = rt[a[i]] = t[i];
        for (int i=2; i<=n; i++)
            lt[i] = min(lt[i], lt[i-1]+1);
        for (int i=n-1; i>0; i--)
            rt[i] = min(rt[i], rt[i+1]+1);
        for (int i=1; i<=n; i++)
            cout << min(lt[i], rt[i]) << "\n "[i+1<=n];
    }
}