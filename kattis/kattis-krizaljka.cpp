#include <bits/stdc++.h>
#define cmax(a,b) a = max(a,b)
#define cmin(a,b) a = min(a,b)
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string a, b;

int f (char c, string s)
{
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == c) return i;
	}
	return -1;
}

signed main()
{
	cin >> a >> b;
	for (int i=0; i<a.size(); i++)
	{
		int r = f(a[i],b);
		if (r > 0)
		{
			for (int j=0; j<b.size(); j++)
			{
				for (int k=0; k<a.size(); k++)
				{
					if (j == r)
					{
						cout << a[k];
					}
					else
					{
						if (k == i) cout << b[j];
						else cout << '.';
					}
				}
				cout << '\n';
			}
			return 0;
		}
	}
}
