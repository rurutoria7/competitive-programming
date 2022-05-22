#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int t, n;

signed main(){
	liyuu_my_wife
	cin >> t;
	while (t--){
		cin >> n;
		int res = 0;
		while (n--){
			int x, y, z;
			cin >> x >> y >> z;
			res += x*z;
		}
		cout << res << '\n';
	}
}
