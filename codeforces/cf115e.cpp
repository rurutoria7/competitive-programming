/*
dp[i]: max solution end with i
dp[i] = max(dp[i-1], dp[j] + gain[j+1,i] - cost(j+1,i)) j+1~i must covered by segment
dp[i] = max(dp[i-1], dp[j] + gain(j+1,i) - cost(j+1,i)) j+1~i is pay to use
考慮更簡單的轉移，不要有太特殊的條件限制
轉移可以笨，但要保證最後還是能拿到最大值

rep(i,1,n)
    src[1~i-1] -= pay[i]
    for x in segs[i]:
        src[1~x.l-1] += x.gain[i]
    dp = max(dp, max(src[1~i-1]))
    ans = max(ans, dp)
*/
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

const int N = 2e5+10;

vector<pii> segs[N]; //{l,gain}
int n, m, pay[N];

struct Seg{
    int tr[N<<2], lz[N<<2];
    void init(){
        for (int i=0; i<(N<<2); i++) 
            tr[i] = -9e18;
    }
    void upd (int u, int x){
        tr[u] += x;
        lz[u] += x;
    }
    void push (int u){
        upd(u*2,lz[u]);
        upd(u*2+1,lz[u]);
        lz[u] = 0;
    }
    void pull (int u){
        tr[u] = max(tr[u*2], tr[u*2+1]);
    }
    void modify (int ql, int qr, int k, int u=1, int l=0, int r=n){
        if (ql>r || l>qr) return;
        if (ql<=l && r<=qr){
            upd(u,k);
        }
        else{
            push(u);
            int M = (l+r)/2;
            modify(ql,qr,k,u*2,l,M);
            modify(ql,qr,k,u*2+1,M+1,r);
            pull(u);
        }
    }
    int query(int ql, int qr, int u=1, int l=0, int r=n){
        if (ql>r || l>qr) return 0;
        if (ql<=l && r<=qr){
            return tr[u];
        }
        else{
            push(u);
            int M = (l+r)/2;
            return max(query(ql,qr,u*2,l,M), query(ql,qr,u*2+1,M+1,r));
        }
    }
} src;

signed main(){
    minamisan
    cin >> n >> m;

    rep(i,1,n) cin >> pay[i];
    rep(i,1,m){
        int l, r, p;
        cin >> l >> r >> p;
        segs[r].pb({l,p});
    }

    int ans=0, dp=0;
    rep(i,1,n){
        src.modify(0,i-1,-pay[i]);
        for (auto x: segs[i]){
            src.modify(0,x.ff-1,x.ss);
        }
        dp = max(dp, src.query(0,i-1));
        src.modify(i,i,dp);
        ans = max(ans, dp);
    }
    cout << ans << '\n';
}
