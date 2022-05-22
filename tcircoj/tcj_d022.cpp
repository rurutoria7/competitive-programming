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

const int M = 1e9+9;

pii operator * (pii i, pii j){
    return {(i.ff*j.ff%M + 2*i.ss*j.ss%M)%M, (i.ff*j.ss%M+i.ss*j.ff%M)%M};
}

pii qpow (pii x, int n){ 
    pii r = {1,0};
    while (n){
        if (n&1){
            r = r*x;
        }
        x = x*x;
        n>>=1;
    }
    return r;
}

signed main(){
    int x, y, n;
    cin >> x >> y >> n;
    pii res = qpow({x,y},n);
    cout << res.ff << ' ' << res.ss << '\n';
}