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

int a, b, c, sum, flag;

signed main(){
	cin >> a >> b >> c >> sum;
	for (int i=0; a*i<=sum; i++){
		for (int j=0; b*j<=sum-a*i; j++){
			for (int k=0; c*k<=sum-a*i-b*j; k++){
				if (a*i+b*j+c*k == sum){
					cout << i << ' ' << j << ' ' << k << '\n';
					flag = 1;
				}	
			}
		}
	}
	if (!flag) cout << "impossible\n";
}
