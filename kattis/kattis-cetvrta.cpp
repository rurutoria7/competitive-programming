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

int a, b, c, d, e, f;

signed main(){
	cin >> a >> b >> c >> d >> e >> f;
	cout << (max(a,max(c,e))+min(a,min(c,e)))*2-a-c-e << ' ' << (max(b,max(d,f))+min(b,min(d,f)))*2-b-d-f << '\n';
}
