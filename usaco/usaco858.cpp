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

int n, m, c, a[N];

int check (int x){
	int head = 1, cnt=1;
	rep(i,1,n){
		if (a[i]-a[head]<=x && i-head+1<=c);
		else{
			cnt++, head = i;
		}
	}	
	return cnt<=m;
}

int bs (){
	int i=-1, s=1e9;
	while (s){
		if (i+s>1e9 || check(i+s)) s>>=1;
		else i += s;
	}
	return i+1;
}

signed main(){
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	cin >> n >> m >> c;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);

	cout << bs() << '\n';
}
