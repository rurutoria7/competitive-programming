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

int l, d, x;

signed main(){
	cin >> l >> d >> x;
	int mx = 0, mn = 9e18;
	rep(i,l,d){
		int cnt = 0, w = i;
		while (w) cnt += w%10, w/=10;
		if (cnt == x) mx = max(i,mx), mn = min(i,mn);
	}
	cout << mn << '\n' << mx << '\n';
}
