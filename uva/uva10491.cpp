#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define double long double
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

double cow, car, show;

signed main(){
	liyuu_my_wife

	while (cin >> cow >> car >> show)
		cout << fixed << setprecision(5) << car/(cow+car)*(car-1)/(cow+car-show-1)+cow/(cow+car)*car/(cow+car-show-1) << '\n';
}
