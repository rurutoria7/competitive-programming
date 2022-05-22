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

const int N = 2e5+10;
int go[N][30], n, q;

signed main(){
    minamisan
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> go[i][0];
    }

    for (int j=1; j<30; j++){
        for (int i=1; i<=n; i++){
            go[i][j] = go[go[i][j-1]][j-1];
        }
    }

    while (q--){
        int x, k;
        cin >> x >> k;
        for (int i=0; k>0; k>>=1,i++){
            if (k&1){
                x = go[x][i];
            }
        }
        cout << x << '\n';
    }
}