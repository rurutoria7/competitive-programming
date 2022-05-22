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

const int N = 2e5+10, M = 1e6+10;

int n, a[N], q;
struct Q {int l, r, id;} qs[N];

int ans[N], cnt[M];
void mos()
{
    int blk = sqrt(n);
    sort(qs+1,qs+1+q,[=](Q i, Q j){
        int bid = (i.l-1)/blk;
        int bjd = (j.l-1)/blk;
        if (bid != bjd) return bid < bjd;
        return i.r < j.r;
    });
    int l=1, r=0, power=0;
    rep(i,1,q)
    {
        int ql = qs[i].l, qr = qs[i].r, qid = qs[i].id;
        auto rem = [&](int i)
        {
            power -= 2*cnt[a[i]]*a[i]-a[i], cnt[a[i]]--;
        };
        auto add = [&](int i)
        {
            power += 2*cnt[a[i]]*a[i]+a[i], cnt[a[i]]++;
        };
        while (l<ql) rem(l++);
        while (l>ql) add(--l);
        while (r>qr) rem(r--);
        while (r<qr) add(++r);
        ans[qid] = power;
    }
}

signed main()
{
    liyuu_my_wife
    cin >> n >> q;
    rep(i,1,n) cin >> a[i];
    rep(i,1,q) cin >> qs[i].l >> qs[i].r, qs[i].id = i;
    mos();
    rep(i,1,q) cout << ans[i] << '\n';
}
/*
多次區間查詢價值：區間內所有正整數 i 的 發生次數^2*數字 = Ki*Ki*i

2e5, 

query Ki*i -> range query sum

數量變成平方

每個元素的權重都是在這個序列的發生次數，查詢總和

離線

當新增一個元素 i，總和會增加 2*sum[i] + i

power, sum[]


*/