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

int e, f, c;

signed main(){
	cin >> e >> f >> c;
	e += f;
	int ans=0;
	while (e >= c){
		ans += e/c;
		e = e%c + (e/c);
	}
	cout << ans << '\n';
}
