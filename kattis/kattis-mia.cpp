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

pii a, b;

int cmp (pii x, pii y){
    if (x.ff < x.ss) swap(x.ff,x.ss);
    if (y.ff < y.ss) swap(y.ff,y.ss);
    if (x == y) return 0;
    if (x == pii{2,1}) return 1;
    if (y == pii{2,1}) return -1;
    if (x.ff == x.ss && y.ff == y.ss){
        return x>y? 1:-1;
    }
    if (x.ff == x.ss) return 1;
    if (y.ff == y.ss) return -1;
    return x>y? 1:-1;
}

signed main(){
    liyuu_my_wife
    while (cin >> a.ff >> a.ss >> b.ff >> b.ss, a.ff){
        if (cmp(a,b) == 0) cout << "Tie.\n";
        else if (cmp(a,b) > 0) cout << "Player 1 wins.\n";
        else cout << "Player 2 wins.\n";
    }
}