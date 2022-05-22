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

int n, ans;

signed main()
{
    rr7
    cin >> n;

    for (int i=5; i<=n; i*=5)
    {
        int k = n/i;
        ans += n*k + k - i*(1+k)*k/2;
    }
    cout << ans << '\n';
}