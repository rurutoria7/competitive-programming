#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int n, k;

signed main(){
	cin >> n >> k;
	rep(i,1,n){
		rep(j,1,k){
			rep(l,1,n){
				if ((i+l)&1) rep(m,1,k) cout << ' ';
				else rep(m,1,k) cout << '*';
			}
			dd
		}
	}
}
