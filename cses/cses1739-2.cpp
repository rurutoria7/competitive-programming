#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1010;
struct BIT
{
	int bit[N][N],n,m;
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int y,int d){
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=n;j+=lowbit(j))
			bit[i][j]+=d;
	}
	int sum(int x,int y){
		int num=0;
		for(int i=x;i>0;i-=lowbit(i))
			for(int j=y;j>0;j-=lowbit(j))
			num+=bit[i][j];
		return num;
	}
} bit;

int n, q, a[N][N];

signed main()
{
	roadroller
	cin >> n >> q;

	bit.n = bit.m = n;
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			char c;
			cin >> c;
			a[i][j] = c == '*';
			bit.add(i, j, a[i][j]);
		}
	}
	while (q--)
	{
		int opr, u, d, l, r;
		cin >> opr;
		if (opr == 1)
		{
			cin >> u >> d;
			bit.add(u, d, (a[u][d]? -1 : 1));
			a[u][d] ^= 1;
		}
		else
		{
			cin >> u >> l >> d >> r;
			cout << bit.sum(d,r) - bit.sum(u-1, r) - bit.sum(d,l-1) +  bit.sum(u-1, l-1) << '\n';
		}
	}
}
