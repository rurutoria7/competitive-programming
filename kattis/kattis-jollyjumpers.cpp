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

const int N = 3010, M = 6e5+10;

int vis[M], a[N], n;

signed main(){
	while (cin >> n){
		memset(vis,0,sizeof(vis));
		rep(i,1,n) cin >> a[i];
		rep(i,2,n) vis[abs(a[i]-a[i-1])] = 1;
		int flag = 0;
		rep(i,1,n-1){
			if (vis[i] == 0)
				flag = 1;
		}
		cout << (flag? "Not Jolly":"Jolly") << '\n';
	}
}
