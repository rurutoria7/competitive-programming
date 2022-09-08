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

const int N = 1e5+10;

pii a[N]; //{time,dl}
int n;

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i].ff;
	rep(i,1,n) cin >> a[i].ss;
	sort(a+1,a+1+n);

	int nt=0, sum=0;
	rep(i,1,n){
		nt += a[i].ff;	
		sum += a[i].ss - nt;
	}	
	cout << sum << '\n';
}
