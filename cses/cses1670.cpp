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

const int N = 3;

vector<pii> sw;
int t[20];

int swapp(pii p, int x)
{
	return x - x/t[p.ff]%10*t[p.ff] - x/t[p.ss]%10*t[p.ss] + x/t[p.ff]%10*t[p.ss] + x/t[p.ss]%10*t[p.ff];
}

int bfs(int ouo)
{
	unordered_map<int,int> dis;
	queue<int> q;
	q.push(ouo);
	while(q.size())
	{
		int x = q.front(), d = dis[x];
		q.pop();
		if (x == 123456789LL)
		{
			return d;
		}
		for (auto p: sw)
		{
			int ns = swapp(p, x);
			if (dis[ns]) continue;
			dis[ns] = d+1;
			q.push(ns);
		}			
	}	
}

signed main()
{
	rep(i,0,5) sw.pb({i, i+3});
	rep(i,0,2) sw.pb({i*3, i*3+1}), sw.pb({i*3+1, i*3+2});
	t[0] = 1; rep(i,1,10) t[i] = t[i-1]*10;

	int init = 0;
	rep(i,0,8)
	{
		int x;
		cin >> x;
		init = init*10 + x;
	}	
	cout << bfs(init) << '\n';
}
