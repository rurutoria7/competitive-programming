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

const int N = 100;

int n, a[N], u;

signed main(){
	while (cin >> n, n){
		int sum = 0;
		rep(i,1,n) cin >> a[i], sum += a[i];
		int ans = 0;
		rep(i,1,n) ans += max(0LL,a[i]-sum/n);
		cout << "Set #" << ++u << '\n';
		cout << "The minimum number of moves is " << ans << ".\n\n";
	}
}
