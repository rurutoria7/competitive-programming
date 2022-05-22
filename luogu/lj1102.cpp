#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

map<int,int> cnt;
int n, c, a[N];

signed main(){
	cin >> n >> c;
	rep(i,1,n){
		cin >> a[i];
	}	
	int sum = 0;
	rep(i,1,n){
		sum += cnt[c+a[i]];
		sum += cnt[a[i]-c];
		cnt[a[i]]++;
	}
	cout << sum << '\n';
}
