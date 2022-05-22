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

const int N = 100;

char c[N][N];
int n, m, t, q;

int exi (int opr, int opc, string &s, int dr, int dy){
	for (int i=0; i<s.size(); i++){
		if (opr+dr*i<1 || opr+dr*i>n || opc+dy*i<1 || opc+dy*i>m || c[opr+dr*i][opc+dy*i] != s[i])
			return 0;
	}
	return 1;
}

signed main(){
	liyuu_my_wife
	cin >> t;
	int owowo = 0;
	while (t--){
		if (owowo) cout << '\n';
		else owowo = 1;
		cin >> n >> m;
		rep(i,1,n) rep(j,1,m) cin >> c[i][j];
		rep(i,1,n){
			rep(j,1,m){
				if ('A' <= c[i][j] && c[i][j] <= 'Z')
					c[i][j] -= 'A', c[i][j] += 'a';
			}
		}
		cin >> q;
		while (q--){
			string s;
			cin >> s;
			for (int i=0; i<s.size(); i++)
				if ('A'<=s[i] && s[i]<='Z')
					s[i] -= 'A', s[i] += 'a';
			int flag = 0;
			rep(i,1,n){
				rep(j,1,m){
					rep(x,-1,1){
						rep(y,-1,1)
							if (exi(i,j,s,x,y)){
								cout << i << ' ' << j << '\n';
								flag = 1;
								break;
							}
						if (flag) break;
					}
					if (flag) break;
				}
				if (flag) break;
			}
		}
	}
}
