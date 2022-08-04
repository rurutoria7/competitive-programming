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
const int N = 20;

int fx, fy, t, sx, sy, ex, ey;
int n = 10, m = 17;
string G[N] = 
{
    "*****************",
    "*...*.......**..*",
    "**..*....*.*.*..*",
    "*......*.**.**.**",
    "*..**...**..**.**",
    "**.....**..*.*..*",
    "*....*..........*",
    "*.....****.*...**",
    "****.*.*........*",
    "*****************"
};
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int onFire[N][N];
void bfs1()
{
    queue<pii> q;
    q.push({fx,fy});
    memset(onFire,-1,sizeof(onFire));
    onFire[fx][fy] = 1;
    
    while (q.size())
    {
        int x = q.front().ff, y = q.front().ss;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nx = x+step[i][0], ny = y+step[i][1];
            if (G[nx][ny] == '.' && !(nx==ex && ny==ey) && onFire[nx][ny]<0)
            {
                onFire[nx][ny] = onFire[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

int dep[N][N];
int bfs2()
{
    if (t >= onFire[sx][sy]) return -1;

    queue<pii> q;
    memset(dep,-1,sizeof(dep));
    dep[sx][sy] = t;
    q.push({sx,sy});

    while (q.size())
    {
        int x = q.front().ff, y = q.front().ss;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nx = x+step[i][0], ny = y+step[i][1];
            if (nx == ex && ny == ey)
            {
                return dep[x][y]+1;
            }
            if (dep[nx][ny]<0 && G[nx][ny] == '.' && dep[x][y]+1<onFire[nx][ny])
            {
                dep[nx][ny] = dep[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

signed main()
{
    cin >> fx >> fy >> t >> sx >> sy >> ex >> ey;
    bfs1();
    int ans = bfs2();
    if (ans > 0) cout << ans-t << '\n';
    else cout << "Help!\n";

    // calc onFire(dep), canGo = G[x][y]=='.' && (x,y) != (ex,ey)
    // calc on escape, canGo = G[x][y]=='.' && dep[x][y]+t<onFire[x][y]
}