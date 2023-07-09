#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, m;
pair<int, pii> edg[N];

struct DSU
{
	int p[N];
	void init()
	{
		rep(i,1,n) p[i] = i;
	}
	int find(int i)
	{
		return p[i]==i? i:p[i]=find(p[i]);
	}
	void U(int u, int v)
	{
		p[find(u)] = p[find(v)];
	}
} dsu;

int krus()
{
	int res = 0, cnt = 0;
	sort(edg+1, edg+1+m);
	dsu.init();
	rep(i,1,m)
	{
		int u = edg[i].ss.ff;
		int v = edg[i].ss.ss;
		int w = edg[i].ff;
		if (dsu.find(u) == dsu.find(v))
			continue;
		dsu.U(u, v);
		res += w;
		cnt++;
	}
	return (cnt == n-1? res:-1);
}

signed main()
{
	lyx
	cin >> n >> m;
	rep(i,1,m)
	{
		cin >> edg[i].ss.ff >> edg[i].ss.ss >> edg[i].ff;
	}
	int ans = krus();
	if (ans >= 0) cout << ans << '\n';
	else cout << "IMPOSSIBLE\n";
}
