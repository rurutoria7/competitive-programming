#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

const int N = 5;

int t, m[N], a[N];

pii exgcd(int a, int b){
    if(b == 0) return mp(1, 0);
    pii ans = exgcd(b, a % b);
    return mp(ans.ss, ans.ff - a / b * ans.ss);
}

signed main()
{
	lyx
	cin >> t;
	while (t--)
	{
		rep(i,1,3) cin >> m[i] >> a[i];
		int M = m[1]*m[2]*m[3];
		int res = 0;
		rep(i,1,3)
		{
			int x = (M/m[i]);
			int ix = exgcd(x, m[i]).ff;
			res = (res + a[i]*x%M*ix%M)%M;
		}
		cout << (res+M)%M << '\n';
	}
}

// M * iM = 1 (mod N)
// M * iM = 1 + k*N
// M * iM - k*N = 1
