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

/*
x less, useless
keep the newest one is the most useful
*/
const int N = 1e5+10;

int n;
pii a[N];
vector<pii> st;

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i].ff;
	rep(i,1,n) cin >> a[i].ss;
	sort(a+1,a+1+n);

	rep(i,1,n){
		while (st.size() && st.back().ss<=a[i].ss)
			st.pop_back();
		st.pb(a[i]);
	}
	cout << st.size() << '\n';
}
