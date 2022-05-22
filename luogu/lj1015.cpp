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
const int N = 200;

int n;
string m;

struct Big
{
    int a[N];
    Big (string s)
    {
        memset(a,0,sizeof(a));
        for (int i=s.size()-1,j=0; i>=0; i--,j++)
        {
            a[j] = i;
        }
    }

    int palin ()
    {
        int i = N-1;
        while (a[i]==0) i--;
        for (int j=0; j<i; j++,i--)
        {
            if (a[i] != a[j]) return 0;
        }
        return 1;
    }
    Big rev()
    {
        Big res = {0};
        int i = N-1;
        while (a[i]==0) i--;
        for (int j=0; i>=0; i--,j++) res.a[j] = a[i];
        return res;
    }
};

void solve (Big x)
{
    int cnt = 0;
    while (!x.palin())
    {
        cnt ++;
        if (cnt >= 30) return -1;
        x = x.rev() + x;
    }
    return cnt;
}

signed main()
{
    cin >> n >> m;
    Big x = {m};
    int ans = solve(x);
    cout << (ans<0? "Impossible!":ans) << '\n';
}