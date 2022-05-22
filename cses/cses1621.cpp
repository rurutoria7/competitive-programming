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

const int N = 2e5+10;
int n, a[N];

signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    sort(a+1,a+1+n);
    
    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        ans += a[i]!=a[i-1];
    }
    cout << ans << '\n';
}