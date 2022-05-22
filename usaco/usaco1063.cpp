/*
- 17.14
觀察：每條邊上都會有至少一隻牛
枚舉兩隻牛當上、下
踩在左邊上的牛（左牛）：在 row 上下之中，col 小於 min(上牛，下牛）
踩在右邊上的牛（又牛）：在 row 上下之中，col 大於 max(上牛，下牛）
左牛數量＊右牛數量

1. li san hua
2. 2d prefix sum
3. enum up-cow, bot-cow, ans += l-cow*r-cow
*/
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

const int N = 2510;

int a[N][N], n;
int r[N], c[N];

int query (int u, int d, int l, int r){
	return a[d][r] - a[d][l-1] - a[u-1][r] + a[u-1][l-1];
}

int t[N];
void lsh (int *arr){
	rep(i,1,n) t[i] = arr[i];
	sort(t+1,t+1+n);
	int m = unique(t+1,t+1+n)-t-1;
	rep(i,1,n) arr[i] = lower_bound(t+1,t+1+m,arr[i])-t;
}

signed main(){
	cin >> n;
	rep(i,1,n){
		cin >> r[i] >> c[i];
	}
	lsh(r);
	lsh(c);

	rep(i,1,n) a[r[i]][c[i]]++;
	rep(i,1,n){
		rep(j,1,n){
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}	
	int ans = 0;
	rep(i,1,n){
		rep(j,i,n){
			int u = min(r[i],r[j]);
			int d = max(r[i],r[j]);
			int ll = min(c[i],c[j]);
			int rr = max(c[i],c[j]);
			ans += query(u,d,1,ll)*query(u,d,rr,n);
		}
	}	
	cout << ans+1 << '\n';
}

