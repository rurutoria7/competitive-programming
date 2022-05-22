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

int n, m, p[N];

int check (int f){
	int e=f, cnt=0;
	rep(i,1,n){
		if (f < p[i]) return 0;
		if (e < p[i]){
			cnt++;
			e = f;
		}
		e -= p[i];
	}
	return cnt<=m;
}
int bs(){
	if (check(0)) return 0;
	int i=0,s=1e18;
	while (s>0){
		if (check(i+s)) s>>=1;
		else i+=s;
	}
	return i+1;
}

signed main(){
	cin >> n >> m;
	rep(i,1,n) cin >> p[i];
	cout << bs() << '\n';
}
