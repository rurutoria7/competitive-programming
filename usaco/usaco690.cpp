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

int d[N], n, tmax;

int check (int x){
	multiset<int> s;
	rep(i,1,x) s.insert(0);
	rep(i,1,n){
		int sm = *s.begin() + d[i];
		s.erase(s.begin());
		s.insert(sm);
	}
	return *s.rbegin() <= tmax;	
}

int bs(){
	int i=0;
	for (int dif=N; dif; dif>>=1){
		while (i+dif<N && !check(i+dif)){
			i += dif;
		}
	}
	return i+1;
}

signed main(){
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin >> n >> tmax;
	rep(i,1,n) cin >> d[i];
	cout << bs() << '\n';
}
