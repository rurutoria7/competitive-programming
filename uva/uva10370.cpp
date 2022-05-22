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

int n, a[N], t;

signed main(){
	cin >> t;
	while (t--){
		int cnt = 0, sum = 0;
		cin >> n;
		rep(i,1,n) cin >> a[i];
		rep(i,1,n) sum += a[i];
		rep(i,1,n) cnt += a[i]*n > sum;
		cout << fixed << setprecision(3) << (100.0*cnt/n) << "%\n";
	}
}
