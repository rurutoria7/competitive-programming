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

string s;

signed main(){
    cin >> s;
    int r=1;
    for (int i=1; i*i<=s.size(); i++)
        if (s.size()%i == 0)
            r = i;
    for (int i=0; i<r; i++){
        for (int j=0; j<s.size()/r; j++){
            cout << s[j*r+i];
        }
    }
}