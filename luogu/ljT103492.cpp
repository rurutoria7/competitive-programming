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

const int N = 5e4+10;

int n, m;
vector<int> G[N];

vector<int> memb[N], subs;
int bcnt, d[N], l[N];
void dfs (int u, int p){
	if (u==p && G[u].size()==0){
		memb[++bcnt].pb(u);
		return;
	}
	subs.pb(u);
	int isap = 0, child = 0;
	d[u] = l[u] = d[p]+1;
	for (auto v: G[u]){
		if (v == p) continue;
		if (d[v]){
			l[u] = min(l[u],d[v]);
		}
		else{
			child++;
			dfs(v,u);
			l[u] = min(l[u],l[v]);
			if (l[v] >= d[u]) isap = 1;
		}
	}
	if (u==p && child<=1) isap = 0;
	if (isap || u==p){
		int x;
		bcnt++;
		do{
			memb[bcnt].pb(x=subs.back());		
			subs.pop_back();
		} while (x != u);
		subs.pb(u);
	}
}

signed main(){
	minamisan
	cin >> n >> m;
	rep(i,1,m){
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i,1,n){
		if (!d[i]) dfs(i,i);
	}
	rep(i,1,bcnt){
		for (auto x: memb[i]){
			cout << x << ' ';	
		}
		cout << '\n';
	}
}
