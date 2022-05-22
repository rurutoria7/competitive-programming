#include <bits/stdc++.h>
#define double long double
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

int cnt;
double sum;

signed main()
{
	int n;
	cin >> n;
	rep(i,1,n){
		int x;
		cin >> x;
		if (x >= 0) cnt++, sum += x;
	}
	cout << fixed << setprecision(10) << sum/cnt << '\n';
}
