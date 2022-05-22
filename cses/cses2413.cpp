#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define las(x) (prev(x.end()))
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10, M = 1e9+7;

int d[N], s[N], t, n;

signed main()
{
	d[0] = 1, d[1] = 2;
	s[0] = 1, s[1] = 3;
	for (int i=2; i<N; i++)
	{
		d[i] = 5*d[i-1]%M-2*s[i-2]%M, d[i]+=M, d[i]%=M;
		s[i] = s[i-1]+d[i], s[i]%=M;
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << d[n] << '\n';
	}
}
