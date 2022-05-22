#include <iostream>
#include <algorithm>
#include <unordered_set>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    do
    {
        cout << n << ' ';
        if (n&1) n = n*3+1;
        else n = n/2;
    }
    while (n!=1);
    cout << 1 << '\n';
}