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

const int N = 1010;

int n;
pii a[N];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	sort(a+1,a+1+n);

	int r1=a[1].ff-1, r2=a[1].ss, cnt=1;
	rep(i,2,n){
		if (a[i].ss > r2){
			if (r2+1<a[i].ff){
				cout << "NO\n";
				return 0;
			}
			else if (r1+1>=a[i].ff){
				cnt--;
			}
			else{
				r1=r2;
			}
			r2 = a[i].ss;
			cnt++;
		}
	}
	cout << cnt << '\n';
}
