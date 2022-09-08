#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10;

int n, h[N], w[N];

struct Seg{
	long long val[N<<1];
	void modify (int i, long long x){
		i += n-1;
		for (val[i]=max(x,val[i]); i>1; i>>=1)
			val[i>>1] = max(val[i],val[i^1]);
	}
	long long query (int ql, int qr){
		ql--;
		long long res = 0;
		for (ql+=n,qr+=n; ql<qr; ql>>=1,qr>>=1){
			if (ql&1) res = max(res, val[ql++]);
			if (qr&1) res = max(res, val[--qr]);
		}
		return res;
	}
} src, dp;

int tmp[N];
int lsh (int *arr){
	rep(i,1,n) tmp[i] = arr[i];
	sort(tmp+1,tmp+1+n);
	int len = unique(tmp+1,tmp+1+n)-tmp-1;
	rep(i,1,n) arr[i] = lower_bound(tmp+1,tmp+1+n,arr[i])-tmp;
	return len;
}

signed main(){
	minamisan
	cin >> n;
	rep(i,1,n) cin >> h[i];
	rep(i,1,n) cin >> w[i];
	lsh(h);

	rep(i,1,n){
		long long d = src.query(h[i]+1,n)+w[i];
		long long s = dp.query(1,h[i]-1);
		dp.modify(h[i],d);
		src.modify(h[i],s);
	}
	cout << dp.query(1,n) << '\n';
}