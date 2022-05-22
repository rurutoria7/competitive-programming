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
	int s;
	cin >> s;
	if (s >= 100)     cout << "S\n";
	else if (s >= 90) cout << "A\n";
	else if (s >= 80) cout << "B\n";
	else if (s >= 70) cout << "C\n";
	else if (s >= 60) cout << "D\n";
	else              cout << "F\n";
}
