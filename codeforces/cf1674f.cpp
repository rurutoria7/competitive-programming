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

const int N = 1010;

int n, m, q;
int G[N][N], res, icon;

signed main()
{
    mothersrosario
    cin >> n >> m >> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            char c;
            cin >> c;
            icon += G[i][j] = c=='*';
        }

    for (int k=icon; k<n*m; k++)
    {
        int i = k%n, j = k/n;
        res += G[i][j];
    }
    while (q--)
    {
        int qx, qy, pos;
        cin >> qx >> qy;
        qx--, qy--;
        pos = qy*n+qx;
        
        if (G[qx][qy]==0)
        {
            // cout << "add, ", de(icon), dd;
            if (G[icon%n][icon/n]) res--;//, cout << "res--\n";
            if (pos > icon) res++;//, cout << "res++\n";
            icon++;
        }
        else
        {
            icon--;
            // cout << "remove ", de(icon), dd;
            if (G[icon%n][icon/n]) res++;//,  cout << "res++\n";
            if (pos >= icon) res--;//,  cout << "res--\n";
        }
        G[qx][qy] ^= 1;
        
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=0; j<m; j++)
        //         cout << G[i][j];
        //     cout << '\n';
        // }
        cout << res << '\n';
    }
}
/*
> 0/1 matrix(1000*100), min operation s.t. 1's left and up is 1
> q(2e5) modify, del or add

the final picture is unique
min operations: not in final picture

add:
    if B: res--
    if add in C: res++
remove:
    if B: res++
    if remove in C: res--
*/
