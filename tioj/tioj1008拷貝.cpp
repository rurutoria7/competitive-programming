#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int N = 6, V = 5e3;

int n, cap[N], tar;

struct Node
{
    int w;
    inline int get(int i)
    {
        int tmp = w;
        rep(j,1,i-1) tmp /= 51;
        return tmp % 51;
    }
    inline void set(int i, int x)
    {
        int k = 1;
        rep(j,1,i-1) k*=51;
        w -= get(i)*k;
        w += x*k;
    }
    inline int success()
    {
        rep(i,1,n) if (get(i) == tar) return 1;
        return 0;
    }
};

inline Node fill (const Node &x, int i)
{
    Node res = x;
    res.set(i,cap[i]);
    return res;
}
inline Node clean (const Node &x, int i)
{
    Node res = x;
    res.set(i,0);
    return res;
}
inline Node move (const Node &x, int i, int j)
{
    Node res = x;
    int moved = min(res.get(i), cap[j] - res.get(j));
    res.set(i,res.get(i)-moved);
    res.set(j,res.get(j)+moved);
    return res;
}

struct Queue
{
    int que[V], l, r, sz;
    int pop() { return sz--, que[l++]; }
    void push(int x) { sz++, que[r++] = x; }
} q;

unordered_set<int> dis;

inline void go(Node v, int d)
{
    if (v.success())
    {
        cout << d+1 << endl;
        exit(0);
    }
    if (dis.find(v.w) == dis.end())
    {
        dis.insert(v.w);
        q.push(v.w);
    }
}

void bfs()
{   
    q.push(0);

    int d = 0;
    while(1)
    {
        int cnt = q.sz;
        while (cnt--)
        {
            Node u = {q.pop()};

            rep(i,1,n)
            {
                rep(j,1,n)
                {
                    if (i == j)
                    {
                        go(fill(u,i), d);
                        go(clean(u,i), d);
                    }
                    else
                    {
                        go(move(u,i,j), d);
                    }
                }
            }
        }
        d++;
    }
}

int sol_exist()
{
    int d = cap[1], mx = 0;
    rep(i,1,n) d = __gcd(d, cap[i]), mx = max(cap[i], mx);
    return (tar%d == 0 && mx>=tar);
}

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> cap[i];
    cin >> tar;

    if (sol_exist())
        bfs();
    else
        cout << -1 << '\n';
}