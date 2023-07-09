int p[N], rank[N];

void init()
{
    for (int i=1; i<=n; i++) p[i] = i, rank[i] = i;
}

int query(int x)
{
    if (x == p[x]) return x;
    else return p[x]=query(p[x]);
}

void U(int x, int y)
{
    x = query(x), y = query(y);
    if (x == y) return;
    if (rank[x] < rank[y]) p[x] = y;
    else if (rank[x] > rank[y]) p[y] = x;
    else p[x] = y, rank[y]++;
}