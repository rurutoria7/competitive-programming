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

double x, y, xx, yy;

double dis (double a, double b, double c, double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

signed main()
{
	cin >> xx >> yy >> x >> y;
	double xxx, yyy;
	while (cin >> xxx >> yyy)
	{
		if (dis(x,y,xxx,yyy) > dis(xxx,yyy,xx,yy)*2)
		{
			cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << xxx << "," << yyy << ").\n";
			return 0;
		}
	}
	cout << "The gopher cannot escape.\n";
}
