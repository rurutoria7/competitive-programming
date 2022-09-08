/*
0 1 10 11 100 101 111
query longest continue 1
*/
#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

int t, k;

int sz (int i)
{
    return (i==0? 1 : i);
}
int num (int i)
{
    if (i == 0) return  1;
    else return 1<<(i-1);
}
int ans (int i)
{
    if (i == 0) return 0;
    else return __lg(i)+1;
}

signed main()
{
    lyx
    cin >> t;
    while (t--)
    {
        cin >> k;
        int blk = 0;
        while (k >= sz(blk)*num(blk))
        {
            k -= sz(blk)*num(blk);
            blk++;
        }
        if (k == 0) blk--;
        cout << blk << endl;
    }
}