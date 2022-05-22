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

int n, a[N], k;

int check (int lim){
	int nsum=0, cnt=1;
	rep(i,1,n){
		if (a[i] > lim) return 0;
		if (nsum + a[i] > lim){
			nsum = 0;
			cnt++;
		}
		nsum += a[i];
	}
	return cnt <= k;
}

int bs(){
	int i=0, s=1e18;
	while (s){
		if (i+s>1e18 || check(i+s)) s>>=1;
		else i += s;
	}
	return i+1;
}

signed main(){
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	cout << bs() << '\n';
}
