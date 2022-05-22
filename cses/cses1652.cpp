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

const int N = 1010;

int sum[N][N], n, q;

signed main(){
	minamisan
	cin >> n >> q;
	rep(i,1,n)
		rep(j,1,n){
			char c;
			cin >> c;
			sum[i][j] = (c=='*');
		}
	rep(i,1,n){
		rep(j,1,n){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	while (q--){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1] << '\n';
	}	
}
