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

string s, l;

int search (string pat, string tar){
    int res = 0;
    for (int i=0; i<tar.size(); i++){
        int flag = 1;
        for (int j=0; j<pat.size(); j++){
            if (pat[j] != tar[i+j]){
                flag = 0;
            }
        }
        res += flag;
    }
    return res;
}
int search (set<string> pat, string tar){
    int res = 0;
    for (auto x: pat) res += search(x,tar);
    return res;
}

signed main(){
    liyuu_my_wife
    while (cin >> s, s!="0"){
        cin >> l;
        int ans1 = search(s,l);
        set<string> strs;
        for (int i=0; i<s.size(); i++){
           // de(i), de(s.substr(0,i)+s.substr(i+1,s.size())), dd
            strs.insert(s.substr(0,i)+s.substr(i+1,s.size()));
        }
        int ans2 = search(strs,l);
        strs.clear();
        for (int i=0; i<=s.size(); i++){
            strs.insert(s.substr(0,i)+"A"+s.substr(i,s.size()));
            strs.insert(s.substr(0,i)+"T"+s.substr(i,s.size()));
            strs.insert(s.substr(0,i)+"C"+s.substr(i,s.size()));
            strs.insert(s.substr(0,i)+"G"+s.substr(i,s.size()));
        }
        int ans3 = search(strs,l);
        cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    }
}