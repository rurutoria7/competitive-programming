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

const int N = 30;

int n;
vector<int> blocks[N];
int pos[N];

void clear_above (int x){
    auto &here = blocks[pos[x]];
    while (here.back() != x){
        pos[here.back()] = here.back();
        blocks[here.back()].pb(here.back());
        here.pop_back();
    }
}
void move_above (int x, int y){
    int i = 0;
    auto &here = blocks[pos[x]];
    auto &there = blocks[pos[y]];
    while (here[i] != x) i++;
    for (; i<here.size(); i++)
        there.pb(here[i]), pos[here[i]] = pos[y];
    while (here.back() != x) here.pop_back();
    here.pop_back();
}
void print(){
    for (int i=0; i<n; i++){   
        cout << i << ":";
        for (auto x: blocks[i]){
            cout << ' ' << x;
        }
        cout << '\n';
    }
}

signed main(){
    liyuu_my_wife
    while (cin >> n){
        // init
        for (int i=0; i<n; i++) blocks[i].clear(), blocks[i].pb(i), pos[i] = i;

        string cmd1, cmd2;
        int a, b;
        while (cin >> cmd1){
            if (cmd1[0] == 'q'){
                break;
            }
            else{
                cin >> a >> cmd2 >> b;
                if (pos[a] == pos[b]) continue;
                if (cmd1[0] == 'm')
                    clear_above(a);
                if (cmd2[1] == 'n')
                    clear_above(b);
                move_above(a,b);
            }
        }
        print();
    }
}