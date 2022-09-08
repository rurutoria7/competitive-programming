#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << "="
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, l;
deque<pii> mxq, mnq;
pii a[N];

/*
x less, hard to use
*/

signed main(){
    minamisan
    
    cin >> n >> l;
    rep(i,1,n) cin >> a[i].ff;
    rep(i,1,n) cin >> a[i].ss;

    sort(a+1,a+1+n);

    int ans = 0;
    rep(i,1,n){
        //deque: 1~i useful point
        if (i==1){
            mxq.push_front(a[i]);
            mnq.push_front(a[i]);
        }
        else{  
            while (mxq.size() && mxq.front().ss <= a[i].ss){
                mxq.pop_front();
            }
            while (mnq.size() && mnq.front().ss >= a[i].ss){
                mnq.pop_front();
            }
            while (mxq.size() && a[i].ff-mxq.back().ff>l){
                mxq.pop_back();
            }
            while (mnq.size() && a[i].ff-mnq.back().ff>l){
                mnq.pop_back();
            }
            mxq.push_front(a[i]);
            mnq.push_front(a[i]);
        }
        ans = max(ans, mxq.back().ss-mnq.back().ss);
    }
    cout << ans << '\n';
}