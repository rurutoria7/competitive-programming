#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define SZ(a) ((int)a.size())
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define PB push_back
#define PPB pop_back
#define EB emplace_back
#define F first
#define S second

template<class T> inline bool chmin(T& a, const T& b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if(a < b) { a = b; return true; } return false; }

const double EPS = 1e-9;

#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);

typedef pair<int, int> pdi;


template<class T> struct LiChaoTree {
	static constexpr T INF = numeric_limits<T>::max();
	struct Line {
		T a, b;
		Line(T a, T b) : a(a), b(b) {}
		T operator()(T x) const { return a * x + b; }
	};
	int n;
	vector<Line> fs;
	vector<T> xs;
	LiChaoTree(const vector<T>& xs_) : xs(xs_) {
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		n = SZ(xs);
		fs.assign(2 * n, Line(T(0), INF));
	}
	int index(T x) const { return lower_bound(xs.begin(), xs.end(), x) - xs.begin(); }
	void add_line(T a, T b) { apply(a, b, 0, n); }
	void add_segment(T a, T b, T xl, T xr) {
		int l = index(xl), r = index(xr);
		apply(a, b, l, r);
	}
	inline T get(T x) const {
		int i = index(x);
		T res = INF;
		for(i += n; i; i >>= 1) chmin(res, fs[i](x));
		return res;
	}
	void apply(T a, T b, int l, int r) {
		Line g(a, b);
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) push(g, l++);
			if(r & 1) push(g, --r);
		}
	}
	void push(Line g, int i) {
		int l = i, r = i + 1;
		while(l < n) l <<= 1, r <<= 1;
		while(l < r) {
			int c = (l + r) / 2;
			T xl = xs[l - n], xr = xs[r - 1 - n], xc = xs[c - n];
			Line& f = fs[i];
			if(f(xl) <= g(xl) && f(xr) <= g(xr)) return;
			if(f(xl) >= g(xl) && f(xr) >= g(xr)) {
				f = g;
				return;
			}
			if(f(xc) > g(xc)) swap(f, g);
			if(f(xl) > g(xl)) {
				i = 2 * i;
				r = c;
			} else {
				i = 2 * i + 1;
				l = c;
			}
		}
	}
};


const int N = 2e5+10;

int n, s[N], f[N], dp[N];


signed main(){

	cin >> n >> f[0];
	rep(i,1,n) cin >> s[i];
	rep(i,1,n) cin >> f[i];

	vector<int> x(n+1);
	for (int i=0; i<x.size(); i++) x[i] = f[i];

	LiChaoTree<int> lc(x);

	for (int i=n-1; i>=0; i--){
		if (i == n-1){
			dp[i] = s[n] * f[n-1];
		}
		else{
			dp[i] = lc.get(f[i]);
		}
		lc.add_line(s[i], dp[i]);
		de(i), de(dp[i]), dd
	}

	cout << dp[0] << '\n';

}
