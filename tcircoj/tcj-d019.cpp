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

const int N = 39;

int a[N], n, p;

void dfs (int i, int r, set<int> &s, int ww){
    if (i > r){
        s.insert(ww);
    }
    else{
        dfs(i+1,r,s,ww+a[i]);
        dfs(i+1,r,s,ww);
    }
}

signed main(){
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    set<int> x, y;
    dfs(1,n/2,x,0);
    dfs(n/2+1,n,y,0);
    x.insert(0), y.insert(0);

    int ans = 0;
    for (auto i: x){
        if (*y.begin() > p-i){
            break;
        }
        auto j = --y.upper_bound(p-i);
        ans = max(ans, *j+i);
        //i+j <=p, j<=p-i
    }
    cout << ans << '\n';
}