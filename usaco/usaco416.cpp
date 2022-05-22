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

const int N = 810;

int sum[N][N];
int n, k;

int nr (int i, int j){
	return max(1LL,i+j-1);
}
int nc (int i, int j){
	return max(1LL,n-i+j);
}

signed main(){
	minamisan
	cin >> n >> k;
	rep(i,1,n)
		rep(j,1,n)
			cin >> sum[nr(i,j)][nc(i,j)];	
	rep(i,1,2*n){
		rep(j,1,2*n){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int ans = 0;
	rep(i,1,n){
		rep(j,1,n){
			int r1=i,r2=i,c1=j-k,c2=j+k;
			int nr1=nr(r1,c1), nc1=nc(r1,c1);
			int nr2=nr(r2,c2), nc2=nc(r2,c2);
			ans = max(ans, sum[nr2][nc2] - sum[nr2][nc1-1] - sum[nr1-1][nc2] + sum[nr1-1][nc1-1]);
		}
	}
	cout << ans << '\n';
}
