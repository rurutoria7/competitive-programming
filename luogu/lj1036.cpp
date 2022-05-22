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

int n, k, a[30], np[50000010];

int dfs (int i, int j, int s){
	if (n-i+1 < j) return 0;
	if (j < 0) return 0;
	if (i > n){
		return !np[s] && j==0;
	}
	return dfs(i+1,j-1,s+a[i]) + dfs(i+1,j,s);
}

signed main(){
	np[1] = np[0] = 1;
	for (int i=2; i<5e7; i++){
		for (int j=i*i; j<5e7; j+=i){
			np[j] = 1;
		}
	}
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	cout << dfs(1,k,0) << '\n';
}
