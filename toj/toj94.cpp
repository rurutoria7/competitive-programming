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
	int x;
	cin >> x;
	if (3<=x && x<=5) cout << "Spring!\n";
	else if (6<=x && x<=8) cout << "Summer!\n";
	else if (9<=x && x<=11) cout << "Autumn!\n";
	else cout << "Winter!\n";
}
