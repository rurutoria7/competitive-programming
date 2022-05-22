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

multiset<int> a, b;
int n;

signed main(){
    cin >> n;
    rep(i,1,n){
        int x;
        cin >> x;
        a.insert(x);
    }
    rep(i,1,n){
        int x;
        cin >> x;
        b.insert(x);
    }

    int cnt = 0;
    for (auto it=b.rbegin(); it!=b.rend(); it++,cnt++){
        if (*it <= *a.begin()){
            break;
        }
        else{
            a.erase(prev(a.lower_bound(*it)));
        }
    }
    cout << cnt << '\n';
}