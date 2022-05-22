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

//只要到的比怪獸早，就可以
//有沒有可能怪獸不能更早到邊界，但是可以更早攔著？
//不可能，怪獸更早或同時到路徑上擋著，就一定可以更早到邊界
//multi source bfs, dm
//bfs build a new da, check if a boundary da < dm

const int N = 1010;

int n, m, G[N][N]; //1 can't go
vector<pii> mons, pla;

int dm[N][N], dp[N][N];
pii src[N][N];
char step_name[] = {'U','D','L','R'}, mov[N][N];
pii step[] = {{-1,0},{1,0},{0,-1},{0,1}};
void bfs (vector<pii> &rt, int (&d)[N][N])
{
    queue<pii> q;
    memset(d,-1,sizeof(d));
    for (auto x: rt)
    {
        d[x.ff][x.ss] = 0;
        q.push(x);
    }
    while (q.size())
    {
        int r = q.front().ff;
        int c = q.front().ss;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nr = r+step[i].ff;
            int nc = c+step[i].ss;
            if (nr<1 || nr>n || nc<1 || nc>m || G[nr][nc] || d[nr][nc]>=0)
                continue;
            d[nr][nc] = d[r][c]+1;
            src[nr][nc] = {r,c};
            mov[nr][nc] = step_name[i];
            q.push({nr,nc});
        }
    }
}

void trace (pii rt)
{
    string ans;
    while(rt.ff!=pla[0].ff || rt.ss!=pla[0].ss)
    {
        ans += mov[rt.ff][rt.ss];
        rt = src[rt.ff][rt.ss];
    }
    cout << ans.size() << '\n';
    for (int i=ans.size()-1; i>=0; i--) cout << ans[i];
    cout << '\n';
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n)
    {
        rep(j,1,m)
        {
            char c;
            cin >> c;
            if (c == 'A') pla.pb({i,j});
            if (c == 'M') mons.pb({i,j});
            if (c == '#') G[i][j] = 1;
        }
    }
    bfs(mons,dm);
    bfs(pla,dp);
    rep(i,1,n)
    {
        pii pos[] = {{i,1},{i,m},{1,i},{n,i}};
        rep(j,0,3)
        {
            int r = pos[j].ff, c = pos[j].ss;
            if (dp[r][c] < 0) continue;
            if (dp[r][c] < dm[r][c] || dm[r][c]<0)
            {
                cout << "YES\n";
                trace(pos[j]);
                return 0;
            }
        }
    }
    cout << "NO\n";
}