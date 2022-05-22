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

int n, k, ans;
int sum[N][N];

signed main(){
	freopen("paintbarn.in","r",stdin);
	freopen("paintbarn.out","w",stdout);
	cin >> n >> k;
	rep(i,1,n){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++, y1++, x2++, y2++;
		sum[x1][y1]++;
		sum[x1][y2]--;
		sum[x2][y1]--;
		sum[x2][y2]++;
	}
	rep(i,1,N-1){
		rep(j,1,N-1){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			if (sum[i][j]==k) ans++;
		}
	}
	cout << ans << '\n';
}
