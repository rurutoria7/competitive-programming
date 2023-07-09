#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int maxN = 1e6+10;

int n, nxt[maxN], prv[maxN];

void init(){ // initially: 0 -> 1 -> 2 -> ... -> n -> 0
	nxt[0] = 1;
	prv[0] = n;
	for (int i=1; i<=n; i++){
		if (i == n) nxt[i] = 0;
		else nxt[i] = i+1;
		prv[i] = i-1;
	}
}

void del(int x){ // remove x itself
	if (nxt[x] == 0)
		return;
	nxt[prv[x]] = nxt[x];
}

void ins(int x, int y){ // insert y after x. y should not be in list.
	prv[nxt[x]] = y;
	prv[y] = x;
	nxt[y] = nxt[x];
	nxt[x] = y;
}

void get(int x){ // 1 <= x <= linked_list.length
	int i, p;
	for (i=1,p=nxt[0]; i<=x; i++,p=nxt[p]);
	return p;
}

void print_from_back(){
	for (int i=prev[0]; i!=0; i=prev[i]){
		cout << i << ' ';
	}
	cout << '\n';
}

void print(){
	for (int i=nxt[0]; i!=0; i=nxt[i]){
		cout << i << ' ';
	}
	cout << '\n';
}


signed main(){
	cin >> n >> m;
	ll.init(n);	
	
	while(m--){
		int o, x, y;
		cin >> o;
		if (o == 1){
			cin >> x >> y;
			ll.ins(x, y);
		}
		else{
			cin >> x;
			ll.del(x);
		}
		ll.print();
	}	
}
