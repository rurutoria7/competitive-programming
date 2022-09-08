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

int n;

signed main(){
	liyuu_my_wife
	cin >> n;
	int manh = 0, eucli = 0, cheb = 0;
	rep(i,1,n){
		int x;
		cin >> x;
		manh += abs(x);
		eucli += x*x;
		cheb = max(cheb, abs(x));
	}
	cout << manh << '\n' << fixed << setprecision(10) << sqrt(eucli) << '\n' << cheb << '\n';
}
