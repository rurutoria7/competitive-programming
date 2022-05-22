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

int cnt, sum;
map<int,int> mp;
int n;

signed main(){
	cin >> n;
	mp[0] = 1;
	rep(i,1,n){
		int x;
		cin >> x;
		sum = ((sum+x)%n+n)%n;
		cnt += mp[sum];
		mp[sum]++;
	}
	cout << cnt << '\n';
}
