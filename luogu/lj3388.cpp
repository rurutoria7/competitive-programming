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

vector<int> G[N];

int low[N], dep[N], n, m, bcnt;
vector<int> st, memb[N];
void dfs (int u, int p){
	if (u == p && G[u].size()<1){
		memb[bcnt++].pb(u);
		return;
	}
    low[u] = dep[u] = dep[p]+1;
	st.pb(u);
    for (auto v: G[u]){
        if (v == p) continue;
        if (dep[v]){
            low[u] = min(low[u], dep[v]);
        }
        else{
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dep[u]){
				bcnt++;
				while(1){
					memb[bcnt].pb(st.back());
					if (st.back() == u) break;
					st.pop_back();
				}
            }
        }
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
		if (!dep[i]) dfs(i,i);
	}
	rep(i,1,bcnt){
		for (auto x: memb[i]){
			cout << x << ' ';
		}
		cout << '\n';
	}
}
