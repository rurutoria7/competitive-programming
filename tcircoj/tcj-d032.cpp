#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, ijp, ijw, h[N], wat[N];
vector<pii> walls; //h[i], i

signed main(){
	minamisan
	cin >> n >> ijp >> ijw;
	rep(i,1,n) cin >> h[i], walls.pb({h[i],i});

	sort(walls.begin(), walls.end());

	int l=1, r=n, i=ijp+1, w=ijw;
	while (1){
		if (l+1==r){
			wat[l] = w;
			break;
		}

		while (walls.back().ss<=l || walls.back().ss>=r)
			walls.pop_back();
		int m = walls.back().ss;

	//	de(l), de(r), de(i), de(w), de(m), dd;

		if (i<m){
			if ((m-l)*h[m]>=w){
				r=m;
			}
			else if ((r-m)*h[m]>=w-(m-l)*h[m]){
				rep(j,l,m-1){
					wat[j] = h[m];
				}
				w-=(m-l)*h[m];
				l=m,i=m;
			}
			else{
				rep(j,l,r-1){
					wat[j] = w/(r-l);
				}
				break;
			}
		}
		else{
			if ((r-m)*h[m]>=w){
				l=m;
			}
			else if ((m-l)*h[m]>=w-(r-m)*m){
				rep(j,m,r-1){
					wat[j] = h[m];
				}
				w-=(r-m)*h[m];
				r=m,i=m-1;
			}
			else{
				rep(j,l,r-1){
					wat[j] = w/(r-l);
				}
				break;
			}		
		}
	}
	rep(j,1,n-1) cout << wat[j] << ' ';
	cout << '\n';
}