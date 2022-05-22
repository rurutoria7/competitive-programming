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

const int N = 10;

string text, key;
char tbl[N][N];
int vis[200];
pii pos[200];

void beauti (string &s){
    string res = "";
    for (int i=0; i<s.size(); i++){
        char c = s[i];
        if ('A'<=c && c<='Z') res += c;
        else if ('a'<=c && c<='z') res += c-'a'+'A';
    }
    s = res;
}

void print (char x, char y){
    if (pos[x].ff == pos[y].ff){
        cout << tbl[pos[x].ff][(pos[x].ss+1)%5];
        cout << tbl[pos[y].ff][(pos[y].ss+1)%5];
    }
    else if (pos[x].ss == pos[y].ss){
        cout << tbl[(pos[x].ff+1)%5][pos[x].ss];
        cout << tbl[(pos[y].ff+1)%5][pos[y].ss];
    }
    else{
        cout << tbl[pos[x].ff][pos[y].ss];
        cout << tbl[pos[y].ff][pos[x].ss];
    }
}

signed main(){
    getline(cin,key);
    getline(cin,text);
    key += "ABCDEFGHIJKLMNOPRSTUVWXYZ";
    beauti(key), beauti(text);
    for (int i=0,j=0; j<25; i++)
        if (vis[key[i]]) continue;
        else vis[key[i]] = 1, tbl[j/5][j%5] = key[i], pos[key[i]] = {j/5,j%5}, j++;
    for (int i=0; i<text.size(); i+=2){
        if (i == text.size()-1 || text[i]==text[i+1]){
            print(text[i],'X'), i--;
        }
        else
            print(text[i],text[i+1]);
    }
    cout << '\n';
}