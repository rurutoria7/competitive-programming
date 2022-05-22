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

vector<int> v1, v2;
int n, m;

signed main(){
	cin >> n >> m;
	rep(i,1,m){
		int u, v;
		cin >> u >> v;
		if (u>v){
			v1.pb(i);
		}
		else 
			v2.pb(i);
	}
	if (v1.size() > v2.size()){
		cout << v2.size() << '\n';
		for (auto x: v2) cout << x << '\n';
	}
	else{
		cout << v1.size() << '\n';
		for (auto x: v1) cout << x << '\n';
	}
}
