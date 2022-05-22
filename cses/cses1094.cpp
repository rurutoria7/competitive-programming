#include <iostream>
#define int long long
using namespace std;

int n;

signed main()
{
    cin >> n;
    int x,y,res=0;
    cin >> x;
    for (int i=1; i<n; i++)
    {
        cin >> y;
        res += max(0LL,x-y);
        x = max(x,y);
    }
    cout << res << endl;
}