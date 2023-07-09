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

int t;

signed main()
{
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << s;
		for (int i=s.size()-1; i>=0; i--)
		{
			cout << s[i];
		}
		cout << '\n';
	}
}
