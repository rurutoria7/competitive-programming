#include <iostream>
#define int long long
using namespace std;

const int N = 2e5+10;

int a[N], n;

signed main()
{
    cin >> n;
    for (int i=1; i<=n-1; i++)
        cin >> a[i];

    int x = 0;
    for (int i=1; i<=n; i++)
        x ^= i;
    for (int i=1; i<=n-1; i++)
        x ^= a[i];
    cout << x << endl;
}