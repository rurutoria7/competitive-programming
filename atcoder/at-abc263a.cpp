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

int a[10], vis[10];

signed main()
{
    rep(i,1,5) cin >> a[i];
    sort(a+1, a+1+5);

    int cnt = 0;
    rep(i,1,5)
    {
        cnt++;
        if (i==5 || a[i] != a[i+1])
        {
            vis[cnt]++;
            cnt = 0;
        }
    }
    cout << (vis[2]==1 && vis[3]==1 ? "Yes":"No") << endl;
}