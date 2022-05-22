#include <bits/stdc++.h>
#define double long double
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

signed main(){
    double n, p;
    while (cin >> n >> p){
        cout << pow(p,1.0/n) << '\n';
    }
}