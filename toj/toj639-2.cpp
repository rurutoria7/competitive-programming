#include <bits/stdc++.h>
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

const int N = 12, M = 1e9+7;

struct mat{
    vector<vector<int>> v;
    mat(){
        v.resize(N,vector<int>(N));
    }
    mat operator * (mat y){
        mat res;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                for (int k=0; k<N; k++){
                    res.v[i][j] += v[i][k]*y.v[k][j];
                    res.v[i][j] %= M;
                }
            }
        }
        return res;
    }
    int sum(){
        int res = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                res += v[i][j];
                res %= M;
            }
        }
        return res;
    }
    void print(){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
    }
} A1, A2, dp0, I;

mat qpow (mat x, int y){
    mat res = I;
    for (; y; y>>=1,x=x*x){
        if (y&1){
            res = res*x;
        }
    }
    return res;
}

int n;

signed main(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            A2.v[i][j] = 1-(j>=(N-i));
        }
    }
    for (int i=0; i<N; i++){
        I.v[i][i] = 1;
        dp0.v[0][i] = 1;
    }
    cin >> n;
    mat trans = qpow(A2,n-1);
    dp0 = dp0*trans;
    cout << dp0.sum() << '\n';
}