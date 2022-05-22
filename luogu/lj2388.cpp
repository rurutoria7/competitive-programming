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

int n;

signed main()
{
    cin >> n;
    
    int ans = 0;
    for (int i=5,j=n-4; i<=n; i+=5,j-=5)
    {
        int x = 0;
        for (int k=i; k%5==0; k/=5) x++;
        ans += x*j;
    }
    cout << ans << '\n';
}