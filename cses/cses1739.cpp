#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define lowbit(i) (i&(-i))
using namespace std;
typedef pair<int,int> pii;

const int N = 3010;

int tr[N][N], n, m, q;

int query(int r, int c)
{
    int res = 0;
    for (int i=r; i; i-=lowbit(i))
        for (int j=c; j; j-=lowbit(j))
            res += tr[i][j];
    return res;
}
int qsum (int u, int d, int l, int r)
{
    return query(d,r) - query(u-1,r) - query(d,l-1) + query(u-1,l-1);
}
void change(int r, int c, int x)
{
    x -= qsum(r,r,c,c);
    for (int i=r; i<=n; i+=lowbit(i))
        for (int j=c; j<=m; j+=lowbit(j))
            tr[i][j] += x;
}

signed main()
{
	roadroller
	cin >> n >> q;
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			char c;
			cin >> c;
			change(i, j, c == '*');		
		}
	}
	
	while (q--)
	{
		int opr, x, y, z, w;
		cin >> opr;
		if (opr == 1)
		{
			cin >> x >> y;
			change(x, y, qsum(x,x,y,y)^1);
		}
		if (opr == 2)
		{
			cin >> x >> y >> z >> w;
			cout << qsum(x, z, y, w) << '\n';
		}
	}
}

