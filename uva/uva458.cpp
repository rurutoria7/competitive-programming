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

string s;

signed main(){
	int k = '*'-'1';
	while(getline(cin,s)){
		for (int i=0; i<s.size(); i++){
			cout << (char)(s[i]+k);
		}
		cout << '\n';
	}
}
