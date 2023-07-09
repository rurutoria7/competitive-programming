#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

/*
rem 1~i: guarantee 1~i exist, remove 1~i
	rem i-2
	drem i
	rem single i-1
rem single i: guarantee 1~i-1 not exist, i exist, remove i
	put i-1
	drem i
	rem single i-1
put i: guarantee 1~i not exist, put i
	put i-1
	dput i
*/

void drem(int i, string &ans)
{
	ans += "Move ring " + to_string(i) + " out\n";
}
void dput(int i, string &ans)
{
	ans += "Move ring " + to_string(i) + " in\n";
}

void rem(int i, string &ans);
void rem_single(int i, string &ans);
void put(int i, string &ans);

string remt[30], remst[30], putt[30];

void rem(int i, string &ans)
{
	if (i == 0) return;
	if (remt[i] == "")
	{
		if (i == 1) drem(i, remt[i]);
		else
		{
			rem(i-2, remt[i]);
			drem(i, remt[i]);
			rem_single(i-1, remt[i]);
		}
	}
	ans += remt[i];	
}
void rem_single(int i, string &ans)
{
	if (i == 0) return;
	if (remst[i] == "")
	{
		if (i == 1) drem(i, remst[i]);
		else
		{
			put(i-1, remst[i]);
			drem(i, remst[i]);
			rem_single(i-1, remst[i]);
		}
	}
	ans += remst[i];
}
void put(int i, string &ans)
{
	if (i == 0) return;
	if (putt[i] == "")
	{
		if (i == 1) dput(i, putt[i]);
		else
		{
			put(i-1, putt[i]);
			dput(i, putt[i]);
			rem_single(i-1, putt[i]);
		}
	}
	ans +=  putt[i];
}

signed main()
{
	lyx
	int n;
	cin >> n;
	string ans;
	rem(n, ans);
	cout << ans;
}
