#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

// seg:
//      s[i]: min position of i s.t. s[i]>=curL
//      change(i,x)
//      bs(x): min i s.t. max(s[0],...,s[i])>x

signed main()
{
    // calc pos[i]: positions of i, less
    // sort query by left

    
    // maintain curL
    // for ql, qr in queries:
    //      move curL to ql:
    //          seg.update(a[l], next postion of a[l])
    //      this query's ans = seg.bs min i s.t. max(s[0]...)
}