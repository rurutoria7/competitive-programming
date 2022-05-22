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

/*
- 一個 x 只有一個 output
- F(x) 是一個凸包
表示一個凸包
    vector<pii> 從 ff 以前用第 ss 條直線會更好
遍歷凸包，算出所屬的函數值

calc convex:
    m larger, easy to use
    如果我在你可以用以前就超過你了，那你就沒用
*/
const int N = 1e5+10, M = 5e4+10;

vector<pair<double,pii>> st;
int n, m;
pii line[N], q[N]; //{a,b}, {x, qid}

double interx (pii l1, pii l2){
    return (double)(l2.ss-l1.ss)/(l1.ff-l2.ff);
}

void convex(){
    sort(line+1, line+1+n);

    rep(i,1,n){
        if (i<n && line[i].ff == line[i+1].ff) continue;
        while (st.size()>=2 && interx(line[i],st.back().ss)<=st[st.size()-2].ff){
            st.pop_back();
        }
        if (st.size()){
            st.back().ff = interx(line[i],st.back().ss);
        }
        st.pb({9e18,line[i]});
    }
}

signed main(){
    minamisan
    cin >> n >> m;
    rep(i,1,n) cin >> line[i].ff >> line[i].ss;
    rep(i,1,m) cin >> q[i].ff, q[i].ss = i;

    convex();
    
    sort(q+1,q+1+m);
    int j = 0, ans = 0;
    rep(i,1,m){
        while (q[i].ff > st[j].ff){
            j++;
        }
        ans += st[j].ss.ff*q[i].ff + st[j].ss.ss;
    }
    cout << ans << '\n';
}
