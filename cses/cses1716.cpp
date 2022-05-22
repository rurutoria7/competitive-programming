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

const int N = 2e6+10, M = 1e9+7;

int fac[N], inv[N], n, m;

int qpow (int i, int j){
    int a = 1;
    for (; j; j>>=1){
        if (j&1){
            a = a*i%M;
        }
        i = i*i%M;
    }
    return a;
}

void build(){
    fac[0] = 1;
    for (int i=1 ; i<N; i++)
        fac[i] = fac[i-1]*i%M;
    for (int i=0; i<N; i++)
        inv[i] = qpow(fac[i],M-2);
}

signed main(){
    cin >> n >> m;
    build();
    cout << fac[n+m-1]*inv[n-1]%M*inv[m]%M << '\n';
}
/*
C(n+m-1, n-1)
(n+m-1-1)! / (n-1)! / (m)!
*/