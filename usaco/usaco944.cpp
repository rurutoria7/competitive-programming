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

const int N = 1e5+10;

vector<int> G[N];
int x[N], y[N], n, m;

int vis[N];
void dfs (int i, int &u, int &d, int &l, int &r){
	vis[i] = 1;
	u = max(u, y[i]), d = min(d, y[i]);
	l = min(l, x[i]), r = max(r, x[i]);
	for (auto v: G[i]){
		if (vis[v]) continue;
		dfs(v,u,d,l,r);
	}	
}

signed main(){
	freopen("fenceplan.in","r",stdin);
	freopen("fenceplan.out","w",stdout);
	cin >> n >> m;
	rep(i,1,n) cin >> x[i] >> y[i];
	rep(i,1,m){
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans = 9e18;
	rep(i,1,n){
		if (vis[i]) continue;
		int u=-9e18, d=9e18, l=9e18, r=-9e18;
	   	dfs(i,u,d,l,r);
		ans = min(ans,(u-d)*2 + (r-l)*2);
	}
	cout << ans << '\n';
}
