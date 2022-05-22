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

const int N = 110;

int n;
pii a[N]; //{before, id}

signed main(){
	cin >> n;
	a[1] = {0,1};
	rep(i,2,n) cin >> a[i].ff, a[i].ff++, a[i].ss = i;
	sort(a+1,a+1+n);
	rep(i,1,n) cout << a[i].ss << ' ';
	cout << '\n';	
}
