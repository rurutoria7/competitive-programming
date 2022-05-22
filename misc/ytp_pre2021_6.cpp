#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1010, C = 1e5+10;

struct sushi{
	int plate=0, p, w;
} sus[N];
int n, m, c;

int dp[N][C];
int wsum[N];
int psum[N];
int coup[N];
int sz[N];

signed main(){
	minamisan
	cin >> n >> m >> c;
	rep(i,1,n) cin >> sus[i].p;
	rep(i,1,n) cin >> sus[i].w;
	rep(i,1,m) cin >> coup[i];
	rep(i,1,m) cin >> sz[i];
	rep(i,1,m)
		rep(j,1,sz[i]){
			int x;
			cin >> x;
			sus[x].plate = i;
		}

	sort(sus+1, sus+1+n, [](sushi i, sushi j){
		return i.plate < j.plate;
	});
	rep(i,1,n){
		wsum[i] = wsum[i-1] + sus[i].w;
		psum[i] = psum[i-1] + sus[i].p;
	}

	rep(i,1,n){
		rep(j,0,c){
			if (i==n || sus[i].plate!=sus[i+1].plate){
				if (j+coup[sus[i].plate] >= (psum[i]-psum[i-sz[sus[i].plate]]))
					dp[i][j] = dp[i-sz[sus[i].plate]][
						j-(psum[i]-psum[i-sz[sus[i].plate]])+coup[sus[i].plate]
					]
					+wsum[i]-wsum[i-sz[sus[i].plate]];
			}
			if (j >= sus[i].p)
				dp[i][j] = max(dp[i][j], dp[i-1][j-sus[i].p]+sus[i].w);
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
		
	}
	cout << dp[n][c] << '\n';
}

