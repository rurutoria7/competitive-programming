#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string s;
vector<int> v;

signed main(){
    cin >> s, s = '+'+s;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '+'){
            v.pb(s[i+1]-'0');
        }
        else if (s[i] == '-'){
            v.pb(-s[i+1]+'0');
        }
        else if (s[i] == '*'){
            v.back() *= s[i+1]-'0';
        }
        else if (s[i] == '/'){
            v.back() /= s[i+1]-'0';
        }
    }
    int ans = 0;
    for (auto x: v) ans += x;
    cout << ans << '\n';
}