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

int x;

signed main(){
	cin >> x;
	while (1){
		int sum = 1;
		while (x) sum*=(x%10? x%10:1), x/=10;
		if (sum < 10){
			cout << sum << '\n';
			return 0;
		}
		x = sum;
	}
}
