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

const int N = 10;

int a[N][N];

signed main(){
	rep(i,1,5) rep(j,1,6) cin >> a[i][j];
	rep(i,1,5){
		rep(j,1,6){
			if (a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2]){
				cout << "Yes\n";
				return 0;
			}
			if (a[i][j] == a[i+1][j] && a[i+1][j] == a[i+2][j]){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
}
