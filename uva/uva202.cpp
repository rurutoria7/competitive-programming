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

const int N = 1010, M = 3010;

int pos[M], res[N], bg, len;
void division (int x, int y){
	int i = 0;
	while (x){
		if (pos[x] > 0){
			bg = pos[x];
			len = i-bg;
			return;
		}
		pos[x] = i;
		res[i] = x/y;
		de(i), de(x), de(y), de(res[i]), dd
		x = (x%y)*10;
		i++;
	}
	bg = i, len = 1;
}

signed main(){
	int a, b;
	while (cin >> a >> b){
		//1. cycle lenth
		//2. begin
		division(a,b);
		cout << a << "/" << b << " = " << res[0] << ".";
		for (int i=1; i<bg; i++) cout << res[i];
		cout << "(";
		if (len > 50){
			for (int i=bg; i<bg+50; i++) cout << res[i];
			cout << "...)";
		}
		else{
			for (int i=bg; i<bg+len; i++) cout << res[i];
			cout << ")";
		}
		cout << '\n' << "   " << len << " = number of digits in repeating cycle\n";
	}
}
