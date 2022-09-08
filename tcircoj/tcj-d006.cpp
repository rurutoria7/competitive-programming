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

const int N = 30, P = 10009;

int n, a[N], ans;

void dfs (int i, int m){
    if (i == n+1){
        ans += m == 1;
    }
    else{
        dfs(i+1,m*a[i]%P);
        dfs(i+1,m);
    }
}

signed main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    dfs(1,1);
    cout << ans-1 << '\n';
}