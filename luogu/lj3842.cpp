#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define rr7 ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;


/*
0, 1 <- op
2, 3
...
2n, 2n+1
2n+2, 2n+3 <- ed
*/
const int N = 2e4+10;

int n, p[N<<1];
vector<pii> G[N<<1];

int dis[N<<1];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dijks (int op)
{
    memset(dis,0x3f,sizeof(dis));
    dis[op] = 0;
    pq.push({0,op});

    while (!pq.empty())
    {
        int u = pq.top().ss;
        int d = pq.top().ff;
        pq.pop();

        for (auto e: G[u])
        {
            if (dis[e.ss] > d+e.ff)
            {
                dis[e.ss] = d+e.ff;
                pq.push({dis[e.ss],e.ss});
            }
        }
    }
}

signed main()
{
    cin >> n;
    for (int i=2; i<=2*n; i+=2)
        cin >> p[i] >> p[i+1];
    
    p[0] = p[1] = 1;
    p[2*n+2] = p[2*n+3] = n;

    // u -> v: go down, walk through next level path, end with v
    for (int i=0; i<=2*n+1; i++)
    {
        G[i].pb({1+abs(p[i]-p[i+2])+abs(p[i+2]-p[(i+2)^1]), (i+2)^1});
        G[i].pb({1+abs(p[i]-p[(i+2)^1])+abs(p[i+2]-p[(i+2)^1]), i+2});
    }
    dijks(0);
    cout << dis[2*n+2]-2 << '\n';
}