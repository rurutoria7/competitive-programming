#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <cmath>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;


int t, h, w, h1, w1, h2, w2;

int dis (int x, int y){
    return max(0LL,w-x)*max(0LL,w-x) + max(0LL,h-y)*max(0LL,h-y);
}

signed main(){
    minamisan
    cin >> t;
    while (t--){
        cin >> w >> h;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
        h1 = y2-y1;
        w1 = x2-x1;

        if (h1+h2>h || w1+w2>w){
            cout << -1 << '\n';
        }
        else{
            cout << sqrt(min(dis(x1,y1), min(dis(h-x1,y1), min(dis(x1,h-y1), dis(h-x1,h-y1))))) << '\n';;
        }
    }
}