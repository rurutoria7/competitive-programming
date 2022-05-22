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

int a[N], n;

signed main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    n = unique(a+1,a+1+n)-a-1;
    cout << n << '\n';
    for (int i=1; i<=n; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}