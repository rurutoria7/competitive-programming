#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int a[N], n, x;

signed main()
{
    cin >> n >> x;
    rep(i,1,n) cin >> a[i], a[i] += a[i-1];
    set<int> s;
    rep(i,1,n)
    {
        if (s.lower_bound)
    }
    //a[r] - a[l-1] == x
}