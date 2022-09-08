/*
up left corner is black
white cnt for start with black a[i]/2

1. split componet
2. calc every components's b&w, row i&1 is black
3. for every componet, take min(b, w);
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

const int N = 510;

int n, m;
int colo[N][N], owo[N*N][2], a[N][N], cnt;
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void mark (int i, int j, int c)
{
    if (colo[i][j] != 0) return;
    colo[i][j] = c;
    
    for (int x=0; x<4; x++)
    {
        int ni = i+step[x][0];
        int nj = j+step[x][1];
        if (1<=ni && ni<=n && 1<= nj && nj<=m && a[ni][nj]==a[i][j] && colo[ni][nj]==0)
            mark(ni, nj, c);
    }
}

signed main()
{
    lyx
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    rep(i,1,n) rep(j,1,m) mark(i,j,++cnt);

    rep(i,1,n)
        rep(j,1,m)
            owo[colo[i][j]][(i+j)&1]++;   
    int ans = 0;
    rep(i,1,n*m)
        ans += min(owo[i][0], owo[i][1]);

    // rep(i,1,n)
    // {
    //     rep(j,1,m)
    //     {
    //         cout << colo[i][j] << ' ';
    //     }
    //     dd
    // }

    if (ans == 0)
    {
        cout << 0 << ' ' << 0 << endl;
    }
    else
    {
        cout << 1 << ' ' << ans << endl;
        rep(i,1,n)
            rep(j,1,m)
            {
                //if (owo[colo[i][j]][0] == 0 && owo[colo[i][j]][1]==0) continue;
                if (owo[colo[i][j]][(i+j)&1] < owo[colo[i][j]][((i+j)&1)^1])
                    cout << i << ' ' << j << ' ' << 1 << endl;
                else if (owo[colo[i][j]][(i+j)&1] == owo[colo[i][j]][((i+j)&1)^1] && ((i+j)&1))
                    cout << i << ' ' << j << ' ' << 1 << endl;
            }
    }
}