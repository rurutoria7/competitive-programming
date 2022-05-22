#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string s;
int len[200];

signed main(){
    liyuu_my_wife
    len['W'] = 64, len['H'] = 32, len['Q'] = 16, len['E'] = 8;
    len['S'] = 4, len['T'] = 2, len['X'] = 1;

    while (cin >> s, s!="*"){
        int sum = 0, cnt = 0;
        for (int i=1; i<s.size(); i++){
            if (s[i] == '/'){
                cnt += sum == 64;
                sum = 0;
            }
            else{
                sum += len[s[i]];
            }
        }
        cout << cnt << '\n';
    }
}