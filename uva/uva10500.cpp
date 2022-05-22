#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 50;

int n, m, opr, opc;
int G[N][N]; //1: can walk, 2: blocked

int res[N][N], vis[N][N], movecnt; //0: unknown, 1 can walk, 2: blocked
int step[][2] = {{0,-1},{1,0},{0,1},{-1,0}};
void walk (){
	memset(res,0,sizeof(res));
	memset(vis,0,sizeof(vis));
	movecnt = 0;
	int r = opr, c = opc;
	res[r][c] = 1;
	while (1){
		vis[r][c] = 1;
		int nr = -1, nc = -1;
		for (int i=0; i<4; i++){
			int tr = r+step[i][0], tc = c+step[i][1];
			if (tr<1 || tr>n || tc<1 || tc>m)
				continue;
			res[tr][tc] = G[tr][tc];
			if (res[tr][tc] == 1 && !vis[tr][tc])
				nr = tr, nc = tc;
		}
		if (nr<0 && nc<0) return;
	//	de(r), de(c), de(nr), de(nc), dd
		movecnt++, r = nr, c = nc;
	}
}

void split_line(){
	rep(i,1,m)
		cout << "|---";
	cout << "|\n";
}
void hori_stuff (int i){
	rep(j,1,m)
		cout << "| " << (res[i][j]? (res[i][j]==1? "0":"X") : "?") << " ";
	cout << "|\n";
}

signed main(){
	liyuu_my_wife
	//freopen("out.txt","w",stdout);
	while (cin >> n >> m, n||m){

		cin >> opr >> opc;
		rep(i,1,n){
			rep(j,1,m){
				char c;
				cin >> c;
				G[i][j] = (c=='0'? 1:2);
			}
		}
		walk();
		cout << '\n';
		rep(i,1,n){
			split_line();
			hori_stuff(i);
		}
		split_line();
		cout << '\n';
		cout << "NUMBER OF MOVEMENTS: " << movecnt << '\n';
	}
}
