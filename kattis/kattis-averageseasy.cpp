#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1010;

int suma, sumb, n, m, t;
int a[N], b[N];

signed main(){
	cin >> t;
	while (t--){
		cin >> n >> m;
		rep(i,1,n) cin >> a[i], suma += a[i];
		rep(j,1,m) cin >> b[j], sumb += b[j];
		int ans = 0;
		rep(i,1,n) ans += (a[i]*n<suma && a[i]*m>sumb);
		cout << ans << '\n';
	}
}
