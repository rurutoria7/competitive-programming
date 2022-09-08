#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, a[N], pgcd[N], sgcd[N];

signed main(){
	minamisan
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n){
		pgcd[i] = __gcd(pgcd[i-1], a[i]);
		sgcd[n-i+1] = __gcd(sgcd[n-i+2],a[n-i+1]);
	}
	int ans = pgcd[n];
	rep(i,1,n){
		ans = max(ans, __gcd(pgcd[i-1],sgcd[i+1]));
	}
	cout << ans << '\n';
}
