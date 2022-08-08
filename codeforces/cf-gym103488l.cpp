#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10;

int n, m;
char a[N];

signed main()
{
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n-1) cout << a[i];
    if (a[n] != 'a')
    {
        cout << (char)(a[n]-1);
        rep(i,n+1,m) cout << 'z';
    }
    cout << endl;
}