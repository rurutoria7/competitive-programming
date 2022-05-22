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
int a, b;

signed main(){
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '(') a++;
        else if (s[i] == ')') a--;

        if (a < 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << (a? "NO":"YES") << '\n';
        
}