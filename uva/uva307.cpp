#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define GNN sync_with_stdio(0), cin.tie(0);
using namespace std;

const int N = 100;

int n, a[N], vis[N];

int posb(int st, int rlen, int rcnt, int dlen)
{
	if (rcnt == 0) return 1;
	if (st > n) return 0;

	int res = 0;
	rep(j, st, n)
	{
		if (vis[j]) continue;
		if (a[j] == rlen)
		{
			vis[j] = 1;
			res |= posb(1, dlen, rcnt-1, dlen);
			vis[j] = 0;	
		}
		else if (a[j] < rlen)
		{
			vis[j] = 1;
			res |= posb(j+1, rlen-a[j], rcnt, dlen);
			vis[j] = 0;	
		}
		if (res) return 1;
		if (rlen == dlen) return 0;
		if (a[j] == rlen) return 0;
	}
	return 0;
}

signed main()
{
	while (cin >> n, n)
	{
		int sum = 0;
		rep(i,1,n) cin >> a[i], sum += a[i];
		sort(a+1, a+1+n, [](int x, int y){return x>y;});
		rep(i,1,sum)
		{
			if (sum%i==0 && posb(1, i, sum/i, i))
			{
				cout << i << '\n';
				break;
			}
		}
	}
}
