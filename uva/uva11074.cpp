#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int s, t, n;

void draw (char c, int l){
	rep(i,1,l){
		rep(j,1,n){
			rep(k,1,t) cout << '*';
			rep(k,1,s) cout << c;
		}
		rep(k,1,t) cout << '*';
		dd
	}
}
int u = 0;


signed main(){
	while (cin >> s >> t >> n, s||t||n){
		u++;
		cout << "Case " << u << ":" << '\n';
		rep(i,1,n) draw('*',t), draw('.',s);
		draw('*',t);
		cout << '\n';
	}
}
