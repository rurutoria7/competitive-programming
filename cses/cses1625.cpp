#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define liyuu_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 7;

int vis[10][10];
char pat[N*N*N];
int step[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
string step_name = "UDLR";
int ans = 0;

int vis2[N*N][N*N];
int con (int r, int c, int init=0)
{
    if (!init) memset(vis2,0,sizeof(vis2));
    if (r==N && c==1) return 1;
    vis2[r][c] = 1;
    for (int j=0; j<4; j++)
    {
        int nr = r+step[j][0];
        int nc = c+step[j][1];
        if (nr<1 || nr>N || nc<1 || nc>N || vis2[nr][nc] || vis[nr][nc])
            continue;
        if (con(nr,nc,1))
            return 1;
    }
    return 0;
}

int cango (int r, int c)
{
    return !(r<1 || r>N || c<1 || c>N || vis[r][c]);
}

void dfs (int i, int r, int c)
{
    vis[r][c] = 1;
    //de(i), de(r), de(c), dd
    if (r==N && c==1 && i==N*N)
        ans++;
    else if (r==N && c==1)
    {
        
    }
    else
    {
        for (int j=0; j<4; j++)
        {
            int nr = r+step[j][0];
            int nc = c+step[j][1];
            if (!cango(r,c) || (pat[i]!='?'&&step_name[j]!=pat[i]))
                continue;
        }
    }
    vis[r][c] = 0;
}

signed main()
{
    rep(i,1,N*N-1) cin >> pat[i];
    dfs(1,1,1);
    cout << ans << '\n';
}