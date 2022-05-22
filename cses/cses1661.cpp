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

map<int,int> s;
int sum, n, x;

signed main(){
	cin >> n >> x;
	s[0] = 1;
	int cnt = 0;
	rep(i,1,n){
		int a;
		cin >> a;
		sum += a;
		cnt += s[sum-x];
		s[sum]++;
	}
	cout << cnt << '\n';
}
