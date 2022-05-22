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

signed main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (a>b) swap(a,b);
	if (a>c) swap(a,c);
	if (c<a) swap(c,a);
	if (c<b) swap(c,b);
	cout << (a+b<=c? "no":"yes") << '\n';
}
