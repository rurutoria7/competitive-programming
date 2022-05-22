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

const int N = 5e5+10;

pii a[N];
int n;
int tmp[N];

int solve_and_sort (int l, int r)
{
    if (r-l+1 <= 1)
    {
        return 0;
    }
    int mid = (l+r)/2;
    int res = solve_and_sort(l,mid)+solve_and_sort(mid+1,r);
    for (int k=l,i=l,j=mid+1; i<=mid||j<=r; k++)
    {
        if (j>r || (i<=mid && a[i]<=a[j]))
        {
            tmp[k] = a[i];
            i++;
            res += j-mid-1;
        }
        else
        {
            tmp[k] = a[j];
            j++;
        }
    }
    for (int i=l; i<=r; i++) a[i] = tmp[i];
    return res;
}

signed main()
{
	liyuu_my_wife
    cin >> n;
    rep(i,1,n) cin >> a[i].ss;
    
    cout << solve_and_sort(1,n) << '\n';
}
