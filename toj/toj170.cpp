#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int t, n;
char type;

void print (int sz, int sh=0){
    for (int i=1,b=sz-1+sh,s=1; i<=sz; i++,b--,s+=2){
        rep(j,1,b) cout << ' ';
        rep(j,1,s) cout << '*';
        cout << '\n';
    }
}

signed main(){
    liyuu_my_wife
    cin >> t;
    while (t--){
        cin >> type >> n;

        if (type=='A'){
            print(n);
        }
        if (type=='B'){
            print(n);
            print(n);
        }
        if (type=='C'){
            for (int sh=n-1,sz=1; sh>=0; sh--,sz++){
                print(sz,sh);
            }
        }
        if (type=='D'){
            print(10*n);
        }
        if (type=='E'){
            print(n,2);
            rep(i,1,2*n-1+4) cout << '#';
            cout << '\n';
        }
        if (type=='F'){
            print(2*n);
        }
        if (type=='G'){
            print(3*n);
        }
        if (type=='H'){
            print(7*n);
        }
        if (type=='I'){
            print(4*n-1);
        }
        cout << '\n';
    }
}