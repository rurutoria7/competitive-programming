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

const int N = 100;

char c[N][N];
int n, m, zr, zc;

signed main(){
	liyuu_my_wife
	cin >> n >> m >> zr >> zc;
	rep(i,1,n) rep(j,1,m) cin >> c[i][j];
	rep(i,1,n){
		rep(j,1,zr){
			rep(k,1,m){
				rep(l,1,zc) cout << c[i][k];
			}
			cout << '\n';
		}
	}
}

