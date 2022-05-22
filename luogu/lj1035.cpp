#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int k;

signed main(){
	cin >> k;
	double sum = 0;
	rep(i,1,1000000000){
		sum += (double)(1)/i;
		if (sum > k){
			cout << i << '\n';
			return 0;
		}
	}
}
