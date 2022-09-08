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

int n;
pii a[N];

struct BIT{
	int v[N];
	int query (int i){
		int res = 0;
		for (; i; i-=i&-i)
			res += v[i];
		return res;
	}
	void modify (int i){
		for (; i<=n; i+=i&-i)
			v[i]++;
	}
} bit;

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i].ff, a[i].ss = i;	
	sort(a+1,a+1+n,[](pii i, pii j){
		if (i.ff != j.ff) return i.ff > j.ff;
		return i.ss > j.ss;
	});

	int ans = 0;
	rep(i,1,n){
		ans += bit.query(a[i].ss);	
		bit.modify(a[i].ss);
	}
	cout << ans << '\n';
}
