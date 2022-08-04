#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int t, n, k, s;

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        cout << (((1+k)*k/2)<=s && s<=((n+(n-k+1))*k/2)? "Yes":"No") << '\n';
    }
}