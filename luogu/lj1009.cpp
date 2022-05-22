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

const int N = 200;

struct Big{
    int a[N];
    Big (int x){
        memset(a,0,sizeof(a));
        for (int i=0; x>0; x/=10,i++){
            a[i] = x%10;
        }
    }
    Big operator + (Big x){
        Big res{0LL};
        for (int i=0; i<N; i++){
            res.a[i] = a[i] + x.a[i];
        }
        for (int i=0; i<N-1; i++){
            res.a[i+1] += res.a[i]/10;
            res.a[i] %= 10;
        }
        return res;
    }
    Big operator * (Big x){
        Big res{0LL};
        for (int i=0; i<N; i++){
            for (int j=0; j+i<N; j++){
                res.a[i+j] += x.a[i] * a[j];
            }
        }
        for (int i=0; i<N-1; i++){
            res.a[i+1] += res.a[i]/10;
            res.a[i] %= 10;
        }
        return res;
    }
    void print (){
        if (a[0] == 0) cout << 0 << '\n';
        else{
            int i = N-1;
            while (a[i]==0) i--;
            for (i; i>=0; i--) cout << a[i];
            cout << '\n';
        }
    }
};

signed main(){
    Big fac{1LL}, res{0LL};
    int n;
    cin >> n;
    rep(i,1,n){
        fac = fac*Big(i);
        res = res+fac;
    }
    res.print();
}