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
#define vi vector<long long>
#define vec vector
using namespace std;
typedef pair<int,int> pii;

template<typename T>
struct DINIC{
	static const int MAXN=105;
	static const T INF=INT_MAX;
	int n, LV[MAXN], cur[MAXN];
	struct edge{
		int v,pre;
		T cap,r;
		edge(int v,int pre,T cap):v(v),pre(pre),cap(cap),r(cap){}
	};
	int g[MAXN];
	vector<edge> e;
	void init(int _n){
		memset(g,-1,sizeof(int)*((n=_n)+1));
		e.clear();
	}
	void add_edge(int u,int v,T cap,bool directed=false){
		e.push_back(edge(v,g[u],cap));
		g[u]=e.size()-1;
		e.push_back(edge(u,g[v],directed?0:cap));
		g[v]=e.size()-1;
	}
	int bfs(int s,int t){
		memset(LV,0,sizeof(int)*(n+1));
		memcpy(cur,g,sizeof(int)*(n+1));
		queue<int> q;
		q.push(s);
		LV[s]=1;
		while(q.size()){
			int u=q.front();q.pop();
			for(int i=g[u];~i;i=e[i].pre){
				if(!LV[e[i].v]&&e[i].r){
					LV[e[i].v]=LV[u]+1;
					q.push(e[i].v);
					if(e[i].v==t)return 1;
				}
			}
		}
		return 0;
	}
	T dfs(int u,int t,T CF=INF){
		if(u==t)return CF;
		T df;
		for(int &i=cur[u];~i;i=e[i].pre){
			if(LV[e[i].v]==LV[u]+1&&e[i].r){
				if(df=dfs(e[i].v,t,min(CF,e[i].r))){
					e[i].r-=df;
					e[i^1].r+=df;
					return df;
				}
			}
		}
		return LV[u]=0;
	}
	T dinic(int s,int t,bool clean=true){
		if(clean)for(size_t i=0;i<e.size();++i)
			e[i].r=e[i].cap;
		T ans=0, f=0;
		while(bfs(s,t))while(f=dfs(s,t))ans+=f;
		return ans;
	}
};

const int N = 310, M = 100;
int G[N][N], sh[4][2] = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
int n, m, c;

void dfs(int x, int y, int &cnt, int colo, DINIC<int> &dic){ // add x, y to graph, and remaining
	G[x][y] = 1;

	int id = ++cnt;
	dic.add_edge(id, (colo? M : 0), 1);
	
	for (int k=0; k<4; k++){
		int nx = x + sh[k][0];
		int ny = y + sh[k][1];
		
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || G[nx][ny])
			continue;
		
		dic.add_edge(id, cnt+1, 1);
		dfs(nx, ny, cnt, colo^1, dic);
	}
}


signed main(){
	roadroller
	cin >> n >> m >> c;

	rep(i,1,c){
		int x, y;
		cin >> x >> y;
		x--, y--;
		G[x][y] = 1;	
	}


	DINIC<int> dic;
	int ans = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (G[i][j]) continue;
			int cnt = 0;
			dic.init(M+3);
			dfs(i, j, cnt, 0, dic);
			int d = dic.dinic(0, M);
			ans += cnt - d;
		}
	}
	cout << ans << '\n';	
}


/*
a[0], a[n-1]
0, n
s[0], s[n]
0, n+1
ss[0] s[n+1]

s[i]: a[0] + .. + a[i-1]
ss[i]: s[0] + ... + s[i]
*/

