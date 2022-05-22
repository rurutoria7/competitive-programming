#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
#define last(x) (prev(x.end()))
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;

int n, k, a[N];

multiset<int> L, R;

void era (int x)
{
    if (L.find(x) != L.end())
        L.erase(L.lower_bound(x));
    else
        R.erase(R.lower_bound(x));
}
void ins (int x)
{
    if (L.empty() || x<=*last(L))
    {
        L.insert(x);
    }
    else
    {
        R.insert(x);
    }
}
void bal ()
{
    while (R.size()>L.size())
    {
        L.insert(*R.begin());
        R.erase(R.begin());
    }
    while (L.size()-1>R.size())
    {
        R.insert(*last(L));
        L.erase(last(L));
    }
}

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
    {
        ins(a[i]);
        if (i>k) era(a[i-k]);
        bal();
        if (i>=k) cout << *last(L) << "\n "[i+1<=n];
    }
}