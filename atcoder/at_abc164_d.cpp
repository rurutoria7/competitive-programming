#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n'
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10, M = 2019;

string s;
int x[N], n;
map<int,int> mp;

int qpow (int i, int j){
	int res = 1;
	for (;j;j>>=1,i=i*i%M)
		if (j&1) res = res*i%M;
	return res;
}
pii exgcd (int a, int b){
	if (a==0) return {0,1};
	pii pr = exgcd(b%a,a);
	return {pr.ss - (b/a)*pr.ff, pr.ff};
}
int inv (int a){
	pii res = exgcd(a,M);
	return ((res.ff)%M+M)%M;
}

signed main(){
	cin >> s;
	n = s.size();
	rep(i,1,n) x[i] = (s[i-1]-'0');
	rep(i,1,n) x[i] = (x[i-1]*10 + x[i])%M;
	rep(i,1,n) x[i] = x[i]*inv(qpow(10,i))%M;
	
	int ans = 0;
	mp[0]++;
	rep(i,1,n){
		ans += mp[x[i]];
		mp[x[i]]++;
	}
	cout << ans << '\n';	
}
