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

const int N = 21;

int n, w[1<<N], dp[1<<N], dis[1<<N];

queue<int> q;
void bfs(){
	q.push(0);
	dp[0] = w[0];
	dis[0] = 1;

	while (q.size()){
		int u = q.front();
		q.pop();
		for (int i=0; i<n; i++){
			int v = u^(1<<i);
			if (dis[v]<=dis[u] && dis[v]>0) continue;
			if (dis[v]==0) dis[v]=dis[u]+1, q.push(v);	
			dp[v] = max(dp[v], dp[u]+w[v]);
		}
	}
}

signed main(){
	minamisan
	cin >> n;
	for (int i=0; i<(1<<n); i++){
		cin >> w[i];
	}
	bfs();
	cout << dp[(1<<n)-1] << '\n';
}
