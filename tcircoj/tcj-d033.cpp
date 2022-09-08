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

int n, l, a[N];
map<int,int> cnt;

signed main(){
	minamisan
	cin >> n >> l;
	rep(i,1,n) cin >> a[i];

	int ans = 0;

	rep(i,1,n){
		cnt[a[i]]++;
		if (i-l >= 1){
			cnt[a[i-l]]--;
			if (cnt[a[i-l]]==0){
				cnt.erase(a[i-l]);
			}
		}
		ans = max(ans, (long long)cnt.size());
	}

	cout << ans << '\n';
}
