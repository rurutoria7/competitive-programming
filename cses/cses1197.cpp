#include <bits/stdc++.h>
#define cmax(a,b) a = max(a,b)
#define cmin(a,b) a = min(a,b)
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 3000, M = 2*N;

struct Edg {int u, v, w;} edges[M];
int n, m;

int src[N], dis[N];
int bell ()
{
	int x;
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	rep(i,1,n)
	{
		x = -1;
		rep(j,1,m)
		{
			if (dis[edges[j].v] > dis[edges[j].u]+edges[j].w)
			{
				src[edges[j].v] = edges[j].u;
				dis[edges[j].v] = dis[edges[j].u]+edges[j].w;
				x = edges[j].v;
			}
		}
	}
	rep(i,1,n) de(i), de(dis[i]), de(src[i]), dd
	return x;
}
void trace (int u)
{
	//rep(i,1,n) u = src[u];
	vector<int> ans;
	int till = u;
	while(1)
	{
		de(u), de(till), dd
		ans.pb(u);
		u = src[u];
		if (u == till) break;
	}
	ans.pb(till);
	for (int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
	cout << '\n';
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	int x = bell();
	if (x < 0) cout << "NO\n";
	else cout << "YES\n", trace(x);
}
