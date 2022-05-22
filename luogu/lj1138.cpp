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

const int N = 1e4+10;

int n, a[N], k;

void lsh(){
	sort(a+1,a+1+n);
	n = unique(a+1,a+1+n)-a-1;
}

signed main(){
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	lsh();
	if (k<1 || k>n) cout << "NO RESULT\n";
	else cout << a[k] << '\n';
}
