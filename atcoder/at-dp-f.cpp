#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 3010;

int dp[N][N], n, m;
string s1, s2;
pii src[N][N];

void trace(int i, int j)
{
	if (i==0 || j==0) return;
	trace(src[i][j].ff, src[i][j].ss);
	if (s1[i] == s2[j])
	{
		cout << s1[i];
	}
}

signed main()
{
	lyx
	cin >> s1 >> s2;
	s1 = " " + s1, s2 = " " + s2;
	n = s1.size();
	m = s2.size();
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			if (s1[i] == s2[j])
			{
				src[i][j] = {i-1,j-1};
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				if (dp[i-1][j] > dp[i][j-1])
				{
					src[i][j] = {i-1, j};
					dp[i][j] = dp[i-1][j];
				}
				else
				{
					src[i][j] = {i, j-1};
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}	
	trace(n,m);	
	cout << '\n';
}
