/*

二進位數字，在 ai 位可以 ++，自由安排順序
求 1. 最大和 2. 最大值

1 + 進位 = 1+從自己開始往右有多少個 1

當我把這格射程 1 我左邊的人有可能可以幫我進位（貢獻 2)
我把自己這個進位了 ->  左邊的人幫不到
由右往左放


考慮每個設置的貢獻
改變自己這格，再把某格設成 1（未實現貢獻）
如何讓自己的未實現貢獻都被兌現？
左邊必須有 1
最大和 = 未兌現收益最小 -> 1 最少 -> 順序沒差，都一樣

最大值
枚舉最大值會出現在哪一次
安排順序讓最大值出現在這一次，
我會希望如果在我左邊不會造成進位都設置
在我自己要幾次？
從右到左遍歷，如果可以就放下，否則計算從我向左連續幾個
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

const int N = 2e6+10;

int a[N], n, m, len[N], b[N], sum, sb[N];

int getmax(){
	sort(a+1, a+1+m, [](int i, int j){
		return i>j;
	});

	int ans = 1;
	int i=N-1; //len[i] is prepared
	int j=1; //now to put a[j];

	while (j>0){
		while (a[j] < i){
			len[i-1] = (b[i-1]? len[i]+1:0);
			i--;
		}
		if (b[a[j]]){
			ans = max(ans, len[a[j]]+1);	
		}
		else{
			b[i] = 1;
			len[i] = len[i+1]+1;	
		}
		j--;
	}
	return ans;
}

signed main(){
	cin >> n >> m;
	rep(i,1,n){
		char c;
		cin >> c;
		b[i] = c=='1';
	}	
	rep(i,1,m) cin >> a[i], a[i]++;

	sum += 2*m;	
	// smimulate plus
	rep(i,1,n) sb[i] = b[i], sum += b[i];
	rep(i,1,m){
		sb[a[i]]++;
		for (int j=a[i]; sb[j]>1; j++){
			sb[j] = 0, sb[j+1]++;
		}
	}
	rep(i,1,N-1) sum -= sb[i];
	cout << sum << '\n';

	// add from left to right
	cout << 0 << '\n';
//	cout << getmax() << '\n';	
}
