#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string s;

void rotate (int l, int r){
    int rot = 0;
    for (int i=l; i<r; i++) rot += s[i]-'A';
    for (int i=l; i<r; i++) s[i] = (s[i]-'A'+rot)%26+'A';
}

signed main(){
    cin >> s;
    rotate(0,s.size()/2);
    rotate(s.size()/2,s.size());
    for (int i=0,j=s.size()/2; j<s.size(); i++,j++){
       cout << (char)((s[i]-'A'+s[j]-'A')%26+'A');
    }
    cout << '\n';
}