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

const int N = 1010;
int n;
pii a[N];
vector<pii> st;

int cmp (pii i, pii j){
    if (i.ss != j.ss) return i.ss < j.ss;
    return i.ff>j.ff;
}

signed main(){
    cin >> n;
    rep(i,1,n) cin >> a[i].ff >> a[i].ss;
    sort(a+1,a+1+n,cmp);

    int minl = 9e18;
    rep(i,1,n){
        minl = min(minl, a[i].ff);
        if (st.size() && st.back().ss+1<a[i].ff) continue;
        while (st.size()>1 && a[i].ff<=st[st.size()-2].ss+1)
            st.pop_back();
        if (st.size() && a[i].ff <= st.back().ff)
            st.pop_back();
        st.pb(a[i]);
    }
    if (st[0].ff==minl && st.back().ss==a[n].ss){
        cout << st.size() << '\n';
    }
    else{
        cout << "NO\n";
    }
}