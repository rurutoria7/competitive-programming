/*
如果沒有比更早結束的更多，那就沒意義
在答案最大的前提，結束時間最早的

1. 如果能拿，就 +1
2. 如果不能拿就跳過

如果權重 +1，可能有一些性質
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define rr7 sync_with_stdio(0), cin.tie(0);
using namespace std;

const int N = 2e5+10;

int n, a[N], b[N], id[N];

int cmp (int i, int j)
{
    return b[i] < b[j];
}

signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i];
        id[i] = i;
    }

    sort(id+1, id+1+n, cmp);

    int mxsum = 0, mnend = 0;
    for (int i=1; i<=n; i++)
    {
        if (mnend <= a[id[i]])
        {
            mxsum++;
            mnend = b[id[i]];
        }
    }
    cout << mxsum << '\n';
}