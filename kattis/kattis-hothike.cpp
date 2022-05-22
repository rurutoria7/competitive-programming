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

int n, a[N];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];
	int ans = 1, mx = 9e18, hot = 1;
	rep(i,1,n-2){
		if (max(a[i],a[i+2]) < mx){
			ans = i, mx = max(a[i],a[i+2]);
		}
	}
	cout << ans << ' ' << mx << '\n';
}
