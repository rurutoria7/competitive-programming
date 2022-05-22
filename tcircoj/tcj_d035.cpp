#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << "="
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int a[N], n, vis[N];

signed main(){
    minamisan
    cin >> n;
    rep(i,1,n) cin >> a[i];

    int j = 1, ans = 0;
    rep(i,1,n){
        vis[a[i]]++;
        while (j<i && vis[a[i]]>1){
            vis[a[j]]--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans << '\n';
}
