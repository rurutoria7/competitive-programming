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

int n, a[N];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];
	int sum = 0;
	rep(i,1,n) sum += a[i];
	cout << sum-n+1 << '\n';
}
