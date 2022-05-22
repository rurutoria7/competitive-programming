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

vector<int> G[N], rG[N];

int n, m, vis[N];

int dfs (int u, vector<int> *adj){
	vis[u] = 1;
	int ans = 1;
	for (auto v: adj[u]){
		if (vis[v]) continue;
		ans += dfs(v,adj);
	}	
	return ans;
}

signed main(){
	cin >> n >> m;
	rep(i,1,m){
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		rG[v].pb(u);
	}
	dfs(1,G);
	rep(i,2,n){
		if (vis[i]==0){
			cout << "NO\n";
			cout << 1 << ' ' << i << '\n';
			return 0;
		}
	}
	memset(vis,0,sizeof(vis));
	dfs(1,rG);
	rep(i,2,n){
		if (vis[i]==0){
			cout << "NO\n";
			cout << i << ' ' << 1 << '\n';
			return 0;
		}
	}
	cout << "YES\n";
}
