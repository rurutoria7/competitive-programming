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

int n;

signed main(){
	cin >> n;
	for (int j=n-1,i=1; j>=0; j--,i+=2){
		for (int k=0; k<j; k++) cout << ' ';
		for (int k=0; k<i; k++) cout << '*';
		cout << '\n';
	}
}
