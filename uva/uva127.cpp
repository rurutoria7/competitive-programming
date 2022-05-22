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
typedef string Card;
const int N = 52;

vector<Card> piles[N];

int match (Card x, Card y){
    return x[0]==y[0] || x[1]==y[1];
}
vector<Card> &get_pile(int sh, int i){
    rep(j,1,sh){
        while (i>0 && piles[i-1].empty()) i--;
    
    }
}

signed main(){
    while (1){
        rep(i,1,52){
            Card x;
            cin >> x;
            if (x == '#') return 0;
            piles[i].pb(x);
        }
        while (1){
            int flag = 0;
            rep(i,1,52){
                if (piles[i].empty()) continue;
                if (match(get_pile(3,i).back(),piles[i].back()){
                    get_pile(3,i).pb(piles[i].back());
                    piles[i].pop_back();
                    flag = 1;
                    break;
                }
                if (match(get_pile(1,i).back(),piles[i].back())){
                    get_pile(3,i).pb(piles[i].back());
                    piles[i].pop_back();
                    flag = 1;
                    break;
                }
            }
            if (!flag) break;
        }
        print();
    }
}
