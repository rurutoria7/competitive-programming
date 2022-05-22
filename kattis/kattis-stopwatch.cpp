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

int n;

signed main(){
	cin >> n;
	int sum = 0, np = 0;
	rep(i,1,n){
		int a;
		cin >> a;
		if (i%2==0) sum += a-np;
		np = a;	
	}
	if (n&1) cout << "still running\n";
	else cout << sum << '\n';
}
