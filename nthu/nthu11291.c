#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char G[510][510];
int n, m, t, dis[510][510];
int step[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int dfs(int r, int c)
{
    if (dis[r][c] == 0x3f3f3f3f)
    {
        if (G[r][c] == 'F')
            dis[r][c] = 0;
        if (1<c || c>m || r<1 || r>n || G[r][c]=='#')
            dis[r][c] = 1e8;
        for (int i=0; i<4; i++)
        {
            int nr = r+step[i][0], nc = c+step[i][1];
            if (dfs(nr, nc) < dis[r][c])
                dis[r][c] = dfs(nr, nc) + 1;
        }
    }
    return dis[r][c];
}

signed main()
{
    scanf("%d", &t);
    for (int tt=1; tt<=t; tt++)
    {
        memset(G, 0x3f, sizeof(G));
        scanf("%d%d", &m, &n);
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                scanf("%c", &G[i][j]);
            }
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                printf("%c", G[i][j]);
            }
            printf("\n");
        }        
        int ans;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (G[i][j] == 'S')
                {
                    int ans = dfs(i, j);
                    printf("%d\n", ans);
                }
            }
        }
        if (ans == 1e8) printf("-1\n");
        else printf("%d\n", ans);
    }
}