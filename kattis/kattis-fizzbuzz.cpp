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

int n, x, y;

signed main(){
	cin >> x >> y >> n;
	rep(i,1,n){
		if (i%x==0) cout << "Fizz";
		if (i%y==0) cout << "Buzz";
		if (i%x && i%y) cout << i;
		cout << '\n';
	}
}
