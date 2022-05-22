#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define int long long
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

vector<pii> ele, twt;

signed main(){
    char c;
    while (cin >> c){
        if (ele.empty() || ((ele.back().ff>=11 || ele.back().ss>=11) && abs(ele.back().ss-ele.back().ff)>=2)){
            ele.pb({0,0});
        }
        if (twt.empty() || ((twt.back().ff>=21 || twt.back().ss>=21) && abs(twt.back().ss-twt.back().ff)>=2)){
            twt.pb({0,0});
        }        
        if (c == 'W'){
            ele.back().ff++;
            twt.back().ff++;
        }
        else if (c == 'L'){
            ele.back().ss++;
            twt.back().ss++;
        }
        else{
            break;
        }
    }
    for (auto x: ele){
        cout << x.ff << ':' << x.ss << '\n';
    }
    cout << '\n';
    for (auto x: twt){
        cout << x.ff << ':' << x.ss << '\n';
    }
}