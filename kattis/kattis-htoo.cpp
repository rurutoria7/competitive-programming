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

string mat, tar;
int amt;

int dig (char c){
    if ('0'<=c && c<='9') return c-'0';
    return -1;
}

map<char,int> getcnt (string s){
    map<char,int> res;
    for (int i=0; i<s.size(); i++){
        char c = s[i];
        int cnt = 0;
        if (i == s.size()-1 || dig(s[i+1])<0){
            cnt = 1;
        }
        else{
            i++;
            while (i<s.size() && dig(s[i])>=0){
                cnt *= 10, cnt += dig(s[i]);
                i++;
            }
            i--;
        }
        res[c] += cnt;
    }

    return res;
}

signed main(){
    liyuu_my_wife
    cin >> mat >> amt >> tar;
    map<char,int> mat_cnt = getcnt(mat);
    map<char,int> tar_cnt = getcnt(tar);
    

    int res = 9e18;
    for (auto kvp: tar_cnt){
        if (kvp.ss <= 0) continue;
        res = min(res, mat_cnt[kvp.ff]*amt/kvp.ss);
    }
    cout << res << '\n';
}