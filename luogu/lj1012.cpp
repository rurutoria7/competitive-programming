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
const int N = 200;

int cmp (string x, string y){
	return (x+y > y+x);
}
string a[N];

signed main(){
	int n;
	cin >> n;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) cout << a[i];
	cout << '\n';
}

