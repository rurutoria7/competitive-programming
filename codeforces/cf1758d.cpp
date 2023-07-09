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

int t, n;

signed main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		rep(x,2,n)
		{
			int ouo = (2*x + (n-1))*(n-2)/2;
			int ovo = (int)(sqrt(ouo))*(int)(sqrt(ouo)); 
			if ((int)(sqrt(ouo))*(int)(sqrt(ouo)) == ouo)
			{
				cout << 1 << ' ';
				rep(i,x,x+n-3)
				{
					cout << i << ' ';
				}
				cout << ovo-1 << '\n';	
			}
		}
	}
}
