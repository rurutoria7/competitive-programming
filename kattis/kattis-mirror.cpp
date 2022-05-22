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

int t, n, m;
char a[N][N];

signed main(){
    int cnt = 1;
    cin >> t;
    while (t--){
        cin >> n >> m;
        rep(i,1,n) rep(j,1,m) cin >> a[i][j];
        cout << "Test " << cnt++ << "\n";
        for (int i=n; i>0; i--){
            for (int j=m; j>0; j--){
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}