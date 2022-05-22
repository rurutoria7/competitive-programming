#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 50;

char c[N][N];
int n, m;

string get (int opr, int opc, int dr, int dc){
	string res = "";
	for (int i=opr,j=opc; i<=n&&j<=m&&c[i][j]!='#'; i+=dr,j+=dc){
		res += c[i][j];
	}	
	if (res.size() >= 2) return res;
	else return "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
}

signed main(){
	liyuu_my_wife
	cin >> n >> m;
	rep(i,1,n) rep(j,1,m) cin >> c[i][j];
	vector<string> res;
	rep(i,1,n){
		rep(j,1,m){
			if (c[i][j] == '#') continue;
			if (c[i-1][j]<'a' || c[i-1][j]>'z') res.pb(get(i,j,1,0));
			if (c[i][j-1]<'a' || c[i][j-1]>'z') res.pb(get(i,j,0,1));
		}
	}
	sort(res.begin(), res.end(), [](string x, string y){
		for (int i=0; i<min(x.size(),y.size()); i++)
			if (x[i]!=y[i])
				return x[i]<y[i];
		return x.size()<y.size();
	});
	cout << res[0] << '\n';
}
