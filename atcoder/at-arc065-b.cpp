#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lalb ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e4+10;

int n, k, l, c1[N], c2[N];
vector<int> Ga[N], Gb[N];
map<pii, int> ans;

void dfs(int u, vector<int> G[], int tu[], int colo)
{
	if (tu[u]) return;
	tu[u] = colo;
	for (auto v: G[u])
	{
		dfs(v, G, tu, colo);
	}
}

signed main()
{
	lalb
	cin >> n >> k >> l;
	rep(i,1,k)
	{
		int u, v; cin >> u >> v;
		Ga[u].pb(v);
		Ga[v].pb(u);
	}	
	rep(i,1,l)
	{
		int u, v; cin >> u >> v;
		Gb[u].pb(v);
		Gb[v].pb(u);
	}
	int cnt = 0;
	rep(i,1,n) dfs(i, Ga, c1, ++cnt);
	cnt = 0;
	rep(i,1,n) dfs(i, Gb, c2, ++cnt);
	rep(i,1,n) ans[{c1[i], c2[i]}]++;
	rep(i,1,n) cout << ans[{c1[i], c2[i]}] << ' ';
}
/*
find connected on a & connected on b cnt
<
*/
