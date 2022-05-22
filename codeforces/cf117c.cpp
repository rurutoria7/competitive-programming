/*
給風向字串（循環n），自己決定一個任意長度的方向序列，長度最短為多少才能從達成x 變化 x, y 座標變化 y

假設目標變化量都是正的
1.在一個循環裡，x 變化量 + y 變化量 <= n
當給定變化量 -x + -y = n, 沒救，除非目標變化量為 0
自訂變化量必須只少滿足負變化量
如果還很遠，可以把變化量集中在一維，另一個補齊即可
一次循環後對目標的貢獻量 = n + x 貢獻 + y 貢獻
我可以讓 x 前進不那麼多嗎？ 選擇不要動，可是可能不會是最佳天數，

二分搜：如果天數太多，我可以不要動，就沒有貢獻
如果天數太少，動滿不會到

檢查有個長度為 k 的風向字串，會不會到：
算出該字串的 x 貢獻 y 貢獻
目標 x 貢獻 - x 貢獻 + target y contr - y contr <= k
*/

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

const int N = 1e5+10;

int xmov[N], ymov[N], n, xtar, ytar;
int xmvsum, ymvsum;

int check (int k){ // can len k complete
	int xcont = k/n*xmvsum, ycont = k/n*ymvsum;
	for (int i=0; i<k%n; i++){
		xcont += xmov[i];
		ycont += ymov[i];
	}
	return abs(xtar - xcont) + abs(ytar - ycont) <= k;	
}

int bs(){
	int i=-1,s=1e15;
	if (!check(s)) return -1;
	while (s){
		if (i+s > 1e15 || check(i+s)) s>>=1;
		else i += s;
	}
	return i+1;
}

signed main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;	
	xtar = x2-x1, ytar = y2-y1;
	cin >> n;
	for (int i=0; i<n; i++){
		char c;
		cin >> c;
		if (c == 'U') ymov[i] = 1;
		if (c == 'D') ymov[i] = -1;
		if (c == 'L') xmov[i] = -1;
		if (c == 'R') xmov[i] = 1;
	}
	if (xtar < 0){
		xtar = -xtar;
		for (int i=0; i<n; i++) xmov[i] = -xmov[i];
	}
	if (ytar < 0){
		ytar = -ytar;
		for (int i=0; i<n; i++) ymov[i] = -ymov[i];
	}
	for (int i=0; i<n; i++){
		xmvsum += xmov[i];
		ymvsum += ymov[i];
	}
	cout << bs() << '\n';
}
