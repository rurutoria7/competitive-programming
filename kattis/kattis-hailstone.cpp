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
	int sum = 1;
	while (n>1){
		sum += n;
		if (n&1) n = 3*n+1;
		else n = n/2;
	}
	cout << sum << '\n';
}
