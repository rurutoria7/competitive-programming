#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define SZ(a) ((int)a.size())
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define PB push_back
#define PPB pop_back
#define EB emplace_back
#define F first
#define S second

template<class T> struct Dinic {
	struct Edge {
		int to;
		T cap;
		Edge(int _to, T _cap) : to(_to), cap(_cap) {}
	};
	static constexpr T INF = numeric_limits<T>::max() / 2;
	int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<int> cur, h;
	Dinic() {}
	Dinic(int _n) : n(_n), g(_n) { n = _n; }
	void add_edge(int u, int v, T c) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].PB(SZ(e)); e.EB(v, c);
		g[v].PB(SZ(e)); e.EB(u, 0);
	}
	bool bfs(int s, int t) {
		h.assign(n, -1);
		queue<int> que;
		h[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(int i : g[u]) {
				int v = e[i].to;
				T c = e[i].cap;
				if(c > 0 && h[v] == -1) {
					h[v] = h[u] + 1;
					if(v == t) return true;
					que.push(v);
				}
			}
		}
		return false;
	}
	T dfs(int u, int t, T f) {
		if(u == t) return f;
		T r = f;
		for(int &i = cur[u]; i < SZ(g[u]); ++i) {
			int j = g[u][i];
			int v = e[j].to;
			T c = e[j].cap;
			if(c > 0 && h[v] == h[u] + 1) {
				T a = dfs(v, t, min(r, c));
				e[j].cap -= a;
				e[j ^ 1].cap += a;
				r -= a;
				if(r == 0) return f;
			}
		}
		return f - r;
	}
	T flow(int s, int t) {
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		T ans = 0;
		while(bfs(s, t)) {
			cur.assign(n, 0);
			ans += dfs(s, t, INF);
		}
		return ans;
	}
};



signed main(){
	int n, m;
	cin >> n >> m;
	Dinic<int> dic(n);
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		dic.add_edge(u, v, 1);
	}
	cout << dic.flow(0, n-1) << '\n';
}
