#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e9, T = 1e5;
/*
> on hex grid, min line to generate n(1e9) eq triangles
*/

int t, n;

int calc (int x)
{
	int k = x/3, ans = (12+(k-1)*12)*k/2;
	if (x%3 == 1) ans += 4*k;
	if (x%3 == 2) ans += 8*k+2;
	return ans;
}

int bs (int x)
{
	int i=0, s=T;
	while (s > 0)
	{
		if (calc(i+s) >= x) s >>= 1;
		else i += s;
	}
	return i+1;
}

signed main()
{
	mothersrosario
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << bs(n) << '\n';
	}
}
