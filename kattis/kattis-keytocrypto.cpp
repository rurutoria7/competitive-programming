#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string key, s, mes;

signed main(){
	cin >> mes >> key;
	for (int i=0; i<mes.size(); i++){
		cout << (char)((mes[i]-key[i]+26)%26+'A');
		key += (char)((mes[i]-key[i]+26)%26+'A');
	}
	cout << '\n';
}
