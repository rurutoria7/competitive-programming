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

const int N = 5e4+10;
const double EPS = 1e-3;

int x[N], n;

int check (double r){
	
}

double bs(){
	sort(x+1,x+1+n);
	double i=0, s=1e9;
	while (s > EPS){
		if (check(i+s)) s /= 2;			
		else i += s;
	}
	return i;	
}

signed main(){
	cin >> n;
	rep(i,1,n) cin >> x[i];
	cout << fixed << setprecision(1) << bs() << '\n';
}
