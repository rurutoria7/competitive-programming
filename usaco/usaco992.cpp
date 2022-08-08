#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
giving a weighted graph, each node has people p[i]
construct a subgraph, p[i] on

在 G 內檢查與自己連通的點，是否都有與外界斷聯 nk
如果看過就可以刪了
看錯的次數 = m
看對了就只會看一次
set<int> unvis;
*/

const int N = 2e5+10;

vector<int> iG[N];
set<int> unvis;
int n, m;

int dfs (int u){
	int ans = 1;
	unvis.erase(u);
	int v = *unvis.begin();
	while(unvis.size()){
		auto it = lower_bound(iG[u].begin(), iG[u].end(), v);
		if (it==iG[u].end() || *it!=v){
			ans += dfs(v);	
		}
		auto nx = unvis.upper_bound(v);
		if (nx == unvis.end()) break;
		else v = *nx;
	}
	return ans;
}

signed main(){
	minamisan
	cin >> n >> m;
	rep(i,1,n) unvis.insert(i);
	rep(i,1,m){
		int u, v;
		cin >> u >> v;
		iG[u].pb(v);
		iG[v].pb(u);
	}	
	rep(i,1,n) sort(iG[i].begin(), iG[i].end());
	vector<int> ans;
	rep(i,1,n){
		if (unvis.find(i) != unvis.end()){
			ans.pb(dfs(i));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto x: ans) cout << x << ' ';
	cout << '\n';
}
