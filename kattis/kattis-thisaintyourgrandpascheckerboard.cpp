#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 30;

int a[N][N], n;

signed main(){
    cin >> n;
    rep(i,1,n){
        rep(j,1,n){
            char c;
            cin >> c;
            a[i][j] = c=='B';
        }
    }
    rep(i,1,n){
        int cnt = 0, cnt2=0;
        rep(j,1,n){
            cnt += a[i][j];
            cnt2 += a[j][i];
            if (j<=n-2 && a[i][j] == a[i][j+1] && a[i][j+1]==a[i][j+2]){
                cout << 0 << '\n';
                return 0;
            }
            if (i<=n-2 && a[i][j] == a[i+1][j] && a[i+1][j]==a[i+2][j]){
                cout << 0 << '\n';
                return 0;
            }            
        }
        if (cnt!=n-cnt){
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
}