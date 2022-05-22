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

const int N = 210;

int G[N][N], n, x[N], y[N], p[N];
int vis[N], ans;

int dis (int i, int j){
	return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}
int dfs (int u){
	vis[u] = 1;
	int ans = 1;
	rep(v,1,n){
		if (vis[v] || !G[u][v]) continue;
		ans += dfs(v);
	}
	return ans;
}

signed main(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	cin >> n;
	rep(i,1,n) cin >> x[i] >> y[i] >> p[i];
	rep(i,1,n){
		rep(j,1,n){
			if (dis(i,j) <= p[i]*p[i])
				G[i][j] = 1;
		}
	}
	int ans = 0;
	rep(i,1,n){
		memset(vis,0,sizeof(vis));
		ans = max(ans, dfs(i));
	}
	cout << ans << '\n';
}
