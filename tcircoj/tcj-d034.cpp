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

int n, a[N], cnt[N];


int tmp[N];
int disc(){
	rep(i,1,n) tmp[i] = a[i];
	sort(tmp+1,tmp+1+n);
	int m = unique(tmp+1,tmp+1+n)-(tmp+1);
	rep(i,1,n){
		a[i] = lower_bound(tmp+1,tmp+1+m,a[i])-tmp;
	}
	return m;
}

signed main(){
	minamisan
	cin >> n;
	rep(i,1,n) cin >> a[i];
	int m = disc(); //1~n
	
	int sz=0, ans=9e18, j=1;
	rep(i,1,n){
		cnt[a[i]]++;
		if (cnt[a[i]] == 1){
			sz++;
		}
		while (cnt[a[j]] > 1){
			cnt[a[j]]--;
			j++;
		}

		if (sz == m){
			ans = min(ans, i-j+1);
		}
	}
	cout << ans << '\n';
}
