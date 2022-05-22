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
int n, a[N], k;

signed main(){
    cin >> n >> k;
    rep(i,1,n){
        cin >> a[i], a[i]+=a[i-1];
    }
    int ans=0, cnt=0;
    set<int> s;
    s.insert(0);
    rep(i,1,n){
        //s[i]-s[j] <= k, min s[j] that s[i]-k <= s[j]
        if (a[i]-k >= *s.rbegin()){
            break;
        }
        int x = a[i]-*s.lower_bound(a[i]-k);
        if (x > ans){
            cnt = 1;
            ans = x;
        }
        else if (x == ans){
            cnt++;
        }
        s.insert(a[i]);
    }
    cout << ans << '\n' << cnt << '\n';
}