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
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a,b);
	int a1 = 0, a2 = 0;
	a1 += (a%2==0);
	a1 += (b%2==0);
	a2 += (a%3==0);
	a2 += (b%3==0);
	cout << a1 << ' ' << a2 << '\n';
}
