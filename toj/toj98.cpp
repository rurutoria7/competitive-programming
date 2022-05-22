#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

signed main(){
	int c = 299792458;
	cout << "1 Light-second(LS) is 299792458 metres.\n";
	cout << "1 Light-minute(LM) is " << c*60 << " metres.\n";
	cout << "1 Light-hour(LH) is " << c*60*60 << " metres.\n";
	cout << "1 Light-day(LD) is " << c*60*60*24 << " metres.\n";
	cout << "1 Light-week(LW) is " << c*60*60*24*7 << " metres.\n";
	cout << "1 Light-year(LY) is " << c*60*60*24*365 << " metres.\n";
}
