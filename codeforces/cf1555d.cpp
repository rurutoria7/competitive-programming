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
int n, m, a[N];
int csum[10][N];

void calc (int p, int x, int y, int z){
    int pat[4] = {x,y,z};
    for (int i=1; i<=n; i++){
        csum[p][i] = csum[p][i-1] + 1 - (a[i]==pat[(i-1)%3]);
    }
}

signed main(){
    minamisan
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        a[i] = c-'a'+1;
    }
    calc(1,1,2,3);
    calc(2,1,3,2);
    calc(3,2,1,3);
    calc(4,2,3,1);
    calc(5,3,2,1);
    calc(6,3,1,2);
    while (m--){
        int l, r;
        cin >> l >> r;
        int res = 9e18;
        for (int i=1; i<=6; i++){
            res = min(res, csum[i][r]-csum[i][l-1]);
        }
        cout << res << '\n';
    }
}