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

const int N = 1e5+10;

int a[N], n, tmp[N], m;

signed main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        tmp[i] = a[i];
    }
    sort(tmp+1,tmp+1+n);
    m = unique(tmp+1,tmp+1+n) - tmp - 1;
    for (int i=1; i<=n; i++){
        cout << lower_bound(tmp+1,tmp+1+m,a[i])-tmp-1 << ' ';
    }
}