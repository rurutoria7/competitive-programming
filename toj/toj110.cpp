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
		int n;
		cin >> n;
		for (int i=1,s=1,b=n-1; i<=n-3; i++,s+=2,b--){
			for (int j=0; j<b; j++) cout << ' ';
			for (int j=0; j<s; j++) cout << '*';
			dd
		}
		for (int i=0; i<2*n-1; i++) cout << '*'; dd
		cout << ' ';
		for (int i=0; i<2*n-3; i++) cout << '*'; dd
		for (int i=0; i<2*n-1; i++) cout << '*'; dd
		for (int i=1,s=2*(n-3)-1,b=3; i<=n-3; i++,s-=2,b++){
			for (int j=0; j<b; j++) cout << ' ';
			for (int j=0; j<s; j++) cout << '*';
			dd
		}
	}
}
