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

const int N = 2e5+10;

int n, a[N];

signed main()
{
    liyuu_my_wife
    cin >> n;
    rep(i,1,n) cin >> a[i];
    
    sort(a+1, a+1+n);
    n = unique(a+1,a+1+n)-a-1;

    int ans = 0;
    rep(i,1,n)
    {
        for (int j=1;; j++)
        {
            int x = *prev(lower_bound(a+1,a+1+n,a[i]*(j+1)));
            ans = max(ans, x%a[i]);
            if (j*a[i] > a[n]) break;
        }
    }
    cout << ans << '\n';
}
/*

> max(ai%aj | i<j)

* a1 <= a2 <= a3 <= ... <= an

? enum a2
    we have remainders: ff, a4, a5, ..., an mod a2
    -> a1? 
    x === y (mod b)
    x === ? (mod a)

* ai = 1e6
n = 2e5

* a === b (mod m)
if and only if
ka === kb (mod km)

?range mod ans ask for maximum

* 當模數變小，最大值會直接除倍數

?1. 加入倍數
2. 和原先的最大值取 min

+
56 === 6 (mod 20)
56/5 === 6/5 (mod 4)
1/5 === ? (mod 4)

3: 4, 5, 6, 7, 8, 9
-> 3: 1, 2, 0, 1, 2, 0

3: 5, 6, 7, 9, 10
-> 3: 2, 0, 1, 0, 1
-> 3: 5%3, 6%(3*2), 7%(3*2), 9%(3*3), 10%(3*3)

?
for every ai
    enum ai, ai*2, ai*3, ..., ai*j>an

n = 1e6
n/1, n/2, n/3, ..., n/n
nlogn

?
ai*j-> ai*j, ai*j+1, ai*j+2, ..., ai*(j+1)-1
max number < ai*(j+1)

+
3: 4, 5, 7, 9, 10
3*1, max number < 6, 5 -> 2
3*2, max number < 9, 7 -> 1
3*3, max number < 12, 10 -> 1

?
prev(lower_bound)
lower_bound not exist
every number < x

?
input
sort
rep i, 1, n
    rep j, 1, ai*j>an
        lower_bound(ai*j)
*/