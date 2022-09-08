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

int n, d, t[N];

int can (int m){
	if (m >= n) return 1;
	multiset<int> gt;
	rep(i,1,m) gt.insert(0);
	rep(i,1,n){
		int x = *gt.begin();
		gt.erase(gt.begin());
		if (x+t[i]>d) return 0;
		gt.insert(x+t[i]);
	}
	return 1;
}
int bs(){
	int i=0, s=N;
	while (s){
		if (can(i+s)){
			s>>=1;
		}
		else{
			i += s;
		}
	}
	return i+1;
}

signed main(){
	cin >> n >> d;
	rep(i,1,n) cin >> t[i];
	cout << bs() << '\n';
}
