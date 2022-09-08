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
pii a[N]; //deadline, time
int n, T;

signed main(){
	minamisan
	cin >> T;
	while (T--){
		cin >> n;
		rep(i,1,n) cin >> a[i].ss;
		rep(i,1,n) cin >> a[i].ff;
		sort(a+1,a+1+n);

		int nt = 0, ans = 1;
		rep(i,1,n){
			nt += a[i].ss;
			if (nt > a[i].ff){
				ans = 0;
				break;
			}	
		}
		cout << (ans? "yes":"no") << '\n';
	}
}
