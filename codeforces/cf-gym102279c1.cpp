#include <bits/stdc++.h>
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

const int N = 2010;

int n, p, q, a[N], dp[N][N];

int how_far (int i, int len)
{
	int pos = a[i]+len-1;
	return upper_bound(a+1,a+1+n,pos)-(a+i);
}

int valid (int w)
{
	if (w*p + 2*w*q >= a[n]-a[1]+1) return 1;
	memset(dp,0x3f,sizeof(dp));
	for (int i=0; i<=n; i++) dp[n+1][i] = 0;
	for (int i=n; i>0; i--)
	{
		for (int j=0; j<=p+q; j++)
		{
			dp[i][j] = min(dp[i+how_far(i,w)][j-1], dp[i+how_far(i,2*w)][j]+1);
			if (i==1 && j+dp[i][j] <= p+q && dp[i][j] <= q)
				return 1;
		}
	}	
	return 0;
}

int bs()
{
	int i=0, s=1e9;
	while (s>0)
	{
		if (i+s>1e9 || valid(i+s))
			s >>= 1;
		else 
			i += s;
	}
	return i+1; 
}

signed main()
{
	liyuu_my_wife
	cin >> n >> p >> q;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	if (p+q >= n)
	{
		cout << 1 << '\n';
		return 0;
	}
	cout << bs() << '\n';
}
