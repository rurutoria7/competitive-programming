#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 7, M = 10;

char pat[M*M];

int vis[M][M], ans;

inline int can(int r, int c, int i) //can ith step goto r,c
{
    if (vis[r][c]) return 0;
    if (i != N*N-1 && r == N && c == 1) return 0;
    if (vis[r+1][c] && vis[r-1][c] && !vis[r][c+1] && !vis[r][c-1]) return 0;
    if (!vis[r+1][c] && !vis[r-1][c] && vis[r][c+1] && vis[r][c-1]) return 0;
    return 1;
}

int name2step[200][2], step[][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

void dfs (int r, int c, int i) // now stand on (r,c), to decide ith step
{
    //cout << r << ' ' << c << ' ' << i << endl;
    vis[r][c] = 1;
    if (i >= N*N)
    {
        ans++;
    }
    else
    {
        if (pat[i] != '?')
        {
            int nr = r + name2step[pat[i]][0];
            int nc = c + name2step[pat[i]][1];
            if (can(nr, nc, i)) dfs(nr, nc, i+1);
        }
        else
        {
            rep(j,0,3)
            {
                int nr = r + step[j][0];
                int nc = c + step[j][1];
                if (can(nr, nc, i)) dfs(nr, nc, i+1);
            }
        }
    }
    vis[r][c] = 0;
}

signed main()
{
    name2step['U'][0] = -1, name2step['U'][1] =  0;
    name2step['D'][0] =  1, name2step['D'][1] =  0;
    name2step['L'][0] =  0, name2step['L'][1] = -1;
    name2step['R'][0] =  0, name2step['R'][1] =  1;

    rep(i,1,N*N-1) cin >> pat[i];
    rep(i,0,N+1) vis[0][i] = vis[N+1][i] = vis[i][0] = vis[i][N+1] = 1;
    dfs(1,1,1);
    cout << ans << '\n';
}