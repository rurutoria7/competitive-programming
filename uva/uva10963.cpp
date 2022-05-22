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

signed main(){
	int t;
	cin >> t;
	while (t--){
		int w;
		cin >> w;
		int dif = -1, flag = 0;
		rep(i,1,w){
			int a, b;
			cin >> a >> b;
			if (dif < 0) dif = a-b;
			else if (dif != a-b) flag = 1;
		}
		cout << (flag? "no":"yes") << '\n';
		if (t) cout << '\n';
	}
}
