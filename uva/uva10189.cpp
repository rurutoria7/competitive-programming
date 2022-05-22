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

const int N = 110;

int n, m, G[N][N], ucnt;

signed main(){
	liyuu_my_wife

	while (cin >> n >> m, n||m){
		if (ucnt) cout << '\n';
		cout << "Field #" << ++ucnt << ":\n";
		memset(G,0,sizeof(G));
		rep(i,1,n)
			rep(j,1,m){
				char c;
				cin >> c;
				G[i][j] = c=='*';
			}
		rep(i,1,n){
			rep(j,1,m){
				int cnt = 0;
				cnt = G[i-1][j]+G[i][j+1]+G[i+1][j]+G[i][j-1];
				cnt += G[i-1][j-1]+G[i-1][j+1]+G[i+1][j-1]+G[i+1][j+1];
				if (G[i][j]) cout << '*';
				else cout << cnt;
			}
			cout << '\n';
		}
	}
}
