#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

int n, m, x, y, ux, uy;

pii exgcd(int a, int b){
    if(b == 0) return mp(1, 0);
    pii ans = exgcd(b, a % b);
    return mp(ans.ss, ans.ff - a / b * ans.ss);
}

pii move(pii xy, int a, int b, int g)
{
	int x = xy.ff, y = xy.ss;
	int stepx = b/g, stepy = -a/g;
	if (stepy < 0) stepx *= -1, stepy *= -1;
	while (y < 0)
		x += stepx, y += stepy;
	while (y-stepy >= 0)
		x -= stepx, y -= stepy;
	return mp(x,y);
}

signed main()
{
	cin >> n >> m >> x >> y >> ux >> uy;
	int A = n*uy, B = m*ux, C = x*uy - y*ux, g = __gcd(A,B);
	if (C%g)
	{
		cout << -1 << '\n';
		return 0;
	}
	if (ux == 0)
	{
		cout << 0 << ' ' << m << '\n';
		return 0;
	}
	if (uy == 0)
	{
		cout << n << ' ' << 0 << '\n';
		return 0;
	}
	int flipped = 0;
	if (uy < 0)
	{
		uy*=-1, y = m-y;	
		flipped = 1;
	}
	pii xy = exgcd(A, B);
	xy = move(xy, A, B, g);
	xy.ff = xy.ff*C/g, xy.ss = xy.ss*C/g;
	de(xy.ff*A), de(xy.ss*B), de(C), dd
	de(xy.ff), de(xy.ss), dd



	int xans = 0, yans = 0;
	if (xy.ff%2) xans = n;
	if (xy.ss%2) yans = m;
	if (flipped) yans = m-yans;
	cout << xans << ' ' << yans << '\n';
}
