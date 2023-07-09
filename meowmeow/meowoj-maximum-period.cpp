#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

struct Hash{
	string s;
	const int P = 48763987, M = 1e9+7;
	vector<int> h, pow;
	int n;
	
	Hash(string _s): s(_s){
		n = s.size();
		h.resize(n + 5);
		pow.resize(n + 5);
		pow[0] = 1;
		for (int i=1; i<=n; i++){
			pow[i] = pow[i-1] * P % M;
			h[i] = (h[i-1] + s[i] * pow[i-1] % M)%M;
		}
	}
	
	int isEqual(pii x, pii y){
		if (y.ff < x.ff) swap(x, y);				
		return ((h[x.ss] - h[x.ff-1])%M+M)%M * (pow[y.ff - x.ff])%M ==  ((h[y.ss] - h[y.ff-1])%M+M)%M;
	}	

	void debug(){
		int l1, r1, l2, r2;
		while (cin >> l1 >> r1 >> l2 >> r2){
			de( isEqual(mp(l1, r1), mp(l2, r2) ) ), dd
		}
	}
};

signed main(){
	roadroller
	int n;
	cin >> n;
	string s;
	cin >> s, s = ' ' + s;

	vector<int> sum(n+5);
	for (int i=1; i<=n; i++) cin >> sum[i], sum[i] += sum[i-1];

	Hash hash(s);
	
	auto isPeriod = [&](int len){
		for (int l=1,r=len; l<=n; l+=len, r+=len){
			r = min(r, n);
			if (!hash.isEqual(mp(l, r), mp(1, r-l+1))){
				return 0;
			}
		}
		return 1;
	};

	int ans = -1e18;
	for (int len=1; len<=n; len++){
		if (isPeriod(len)){
			ans = max(ans, sum[len]);
		}	
	}
	cout << ans << '\n';
}
/*
func isPeriod(len):
	for every [l,l+len-1 as r]:
		if not hash_val same as first	
			return 0;
	return 1;
	
for len in 1..n:
	if (isPeriod(i))
		ans = max(ans, sum[i])
cout << ans
*/
