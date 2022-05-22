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

const int N = 310, M = 1e6+10;

int n, a[N], vis[M];

signed main(){
	cin >> n;
	rep(i,1,n) cin >> a[i];
	int u = 0;
	rep(i,1,M-1){
		u++;
		int flag = 1;
		rep(j,1,n)
			if (vis[a[j]%i]==u){
				flag = 0;
				break;
			}
			else
				vis[a[j]%i] = u;
		if (flag){
			cout << i << '\n';
			return 0;
		}
	}
}
