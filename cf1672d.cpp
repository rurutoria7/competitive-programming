#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define mothersrosario ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;
/*


   */

int n, t;
int a[N], b[N], cnt[N];

signed main()
{
    mothersrosario
    cin >> t;
    while (t--)
    {
        cin >> n;
		rep(i,1,n) cnt[i] = 0;
		rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];

        int fail = 0, i = n, j = n, prevb = -1;

		while (i>0 || j>0)
		{
			if (a[i] != b[j])
			{
				if (b[j] == prevb)
					cnt[b[j--]]++;
				else if (cnt[a[i]] > 0)
					cnt[prevb = a[i--]]--;
				else
				{
					fail = 1;
					break;
				}
			}
			else
				prevb = b[j], i--, j--;
		}
		cout << (fail? "NO":"YES") << '\n';
	}	
}

/*
> a1, ..., an, n(2e5)
> b1, ..., bn, permutation of a
> operation: cyclic left shift 
> whether it's possible

b to a, opr reversing

two same, move left one to any left position

if a[i] != b[j]
	1. move b[j] forward, if b[j] == prev b
		j--
		prev b not change
	2. use insert a a[i] here, else if a[i]
		cnt[a[i]]--
		i--
		prev b = a[i]
else
	prev b = b[j]
	i--, j--
i, j
if a[i] != b[j]:
*/

