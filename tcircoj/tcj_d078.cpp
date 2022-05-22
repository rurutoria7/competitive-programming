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

const int N = 2e5+10;

int n, a[N];
vector<int> src;

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n){
		if (src.empty()) src.pb(a[i]);
		else if (src.back() < a[i]) src.pb(a[i]);
		else{
			*lower_bound(src.begin(), src.end(), a[i]) = a[i];
		}
	}
	cout << src.size() << '\n';
}
