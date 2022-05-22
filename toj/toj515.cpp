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
	int cnt = 0, x = n%10;
	while (n>0){
		cnt++;
		if (n%10 != x){
			cout << "OAQ\n";
			return 0;
		}
		n /= 10;
	}
	cout << (cnt==4? "GREAT!!":"OAQ") << '\n';
}
