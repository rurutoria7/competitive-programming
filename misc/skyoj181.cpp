#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;

map<int,int> dp_small;
map<__int128,int> dp;

__int128 st;
int f (){
	if (st < 2e9){
		if (dp_small[st] == 0){
			if (st == 1) dp_small[st] = 1;
			else if (st%2) st=st*3+1, dp_small[(st-1)/3] = f()+1, st = (st-1)/3;
			else st = st/2, dp_small[st*2] = f()+1, st = st*2;
		}
		return dp_small[st];
	}
	else{
		if (dp[st] == 0){
			if (st == 1) dp[st] = 1;
			else if (st%2) st=st*3+1, dp[(st-1)/3] = f()+1, st = (st-1)/3;
			else st = st/2, dp[st*2] = f()+1, st = st*2;
		}
		return dp[st];
	}
}

signed main(){
	int n;
	cin >> n;
	int ans = 1, ans_val = 0;
	rep(i,1,n){
		st = i;	
		if (f() > ans_val) ans = i, ans_val = f();
	}	
	cout << ans << ' ' << ans_val << '\n';
}
