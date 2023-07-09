/*
min permutation of n, s.t. p[1] = x, p[n] = 1, =p[i]%i == 0, 
n = 4, x = 2

2, 4, 3, 1

[2, 3, 4, 5, ..., n] - [x]
2, 3, 4, 5, ..., (n-1)

2 to 2
3 to 3
...
x to 1

number that taken out must be 
n%x == 0


x, 2, 3, ..., y, ..n., 1
1, 2, 3, ..., x, ..y., n

smallest y, y%x == 0
n%y == 0
2x

x, y, n

n/y, min divisor

x*mindiv(n/x)
   */

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

const int N = 2e5+10;
int t, n, x, mnd[N];

void shai()
{
	rep(i,2,N-1)
	{
		if (mnd[i]) continue;
		mnd[i] = i;
		for (int j=i+i; j<N; j+=i)
		{
			if (!mnd[j]) mnd[j] = i;
		}
	}
}

vector<int> res;

void gen()
{
	res.clear();
	int y = x;
	while(1)
	{
		res.pb(y);
		if (y == n) break;
		y *= mnd[n/y];
	}
}

signed main()
{
	lyx
	shai();

	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		int j = 0;
		if (n%x == 0)
		{
			gen();
			cout << x << ' ';
			rep(i,2,n-1)
			{
				if (i == res[j])
				{
					cout << res[j+1] << ' ';
					j++;
				}				
				else cout << i << ' ';
			}
			cout << "1\n";
		}	
		else cout << -1 << '\n';
	}
}
