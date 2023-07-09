#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

struct Treap
{
	int val[N], pri[N], sz[N], cnt;
	
	void pull(int u)
	{
		sz[u] = sz[l[u]] + sz[r[u]];
	}
	int newNode(int v)
	{
		cnt++;
		val[cnt] = v;
		pri[cnt] = rand();
		sz[cnt] = 1;
		return cnt;	
	}
	void split(int u, int k, int &sf, int &pf)
	{
		if (!u) sf = pf = 0;	
		if (sz[l[u]] <= k) sf = u, split(l[u], k, pf, l[u]), pull(u);
		else pf = u, split(r[u], k - sz[l[a]] - 1, r[pf], sf), pull(u);
	}
	int merge(int a, int b)
	{
		if (!a || !b) return (a? a : b);
		if (pri[a] < pri[b])
		{
			merge(r[a], b);
			pull(a);
			return a;
		}
		else
		{
			merge(a, l[b]);
			pull(b);
			return b;
		}
	}
	void insert(int x, int sh
} trp;

signed main()
{

}
