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

void gray(int i, string pre, int rev)
{
	if (i == 0)
	{
		cout << pre << '\n';
		return;
	}
	if (!rev)
	{
		gray(i-1, pre+"0", rev);	
		gray(i-1, pre+"1", !rev);
	}
	else
	{
		gray(i-1, pre+"1", !rev);
		gray(i-1, pre+"0", rev);
	}
}

signed main()
{
	int k;
	cin >> k;
	gray(k, "", 0);
}
