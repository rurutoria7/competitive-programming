#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10, M = 1e9+7;

int fac[N], ifac[N], n;

int qpow(int x, int y)
{
	int res = 1;
	for (; y; y>>=1, x = x*x%M)
		if (y&1) res = res * x % M;
	return res;
}
void build()
{
	fac[0] = ifac[0] = 1;
	rep(i,1,N-1)
	{
		fac[i] = fac[i-1] * i % M;
		ifac[i] = qpow(fac[i], M-2);
	}
}

signed main()
{
	roadroller
	build();

	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << fac[a] * ifac[b] % M * ifac[a-b] % M << '\n';
	}
}
