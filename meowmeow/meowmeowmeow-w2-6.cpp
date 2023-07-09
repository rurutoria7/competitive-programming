#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pb push_back
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define blk(i) ((i)/9/3*3+(i)%9/3)
using namespace std;
typedef pair<int,int> pii;

const int N = 9;

int visr[N][N], visc[N][N], visb[N][N], path[N*N], has_sol;

int dfs(int i)
{
    if (i >= N*N)
    {
        for (int j=0; j<N*N; j++) cout << path[j]+1;
        cout << '\n';
        return 1;
    }
    else if (path[i] < 0)
    {
        for (int j=0; j<N; j++)
        {
            if (!visr[i/9][j] && !visc[i%9][j] && !visb[blk(i)][j])
            {
                visr[i/9][j] = visc[i%9][j] = visb[blk(i)][j] = 1;
                path[i] = j;
                if (dfs(i+1)) return 1;
                visr[i/9][j] = visc[i%9][j] = visb[blk(i)][j] = 0;
                path[i] = -1;
            }
        }
        return 0;
    }
    else return dfs(i+1);
}

signed main()
{
    lyx
    string s;
    while(cin >> s, s != "end")
    {
        has_sol = 0;
        memset(visr, 0, sizeof(visr));
        memset(visc, 0, sizeof(visc));
        memset(visb, 0, sizeof(visb));
        memset(path, 0, sizeof(path));

        for (int i=0; i<N*N; i++)
        {
            if (s[i] == '.') path[i] = -1;
            else path[i] = s[i]-'0'-1;
        }

        int flag = 0;
        for (int i=0; i<N*N; i++)
        {
            if (path[i] >= 0)
            {
                if (visr[i/9][path[i]] || visc[i%9][path[i]] || visb[blk(i)][path[i]])
                {
                    flag = 1;
                    break;
                }
                else
                    visr[i/9][path[i]] = visc[i%9][path[i]] = visb[blk(i)][path[i]] = 1;
            }
        }
        if (flag) cout << "No solution.\n";
        else if (!dfs(0)) cout << "No solution.\n";

        /*
        if (has_sol)
        {
            for (int i=0; i<N*N; i++) cout << path[i]+1;
            cout << '\n';
        }
        else cout << "No solution.\n";
        */
    }
}

/*
567328491132469758489571263843795126795612384216843579351987642628154937974236815
567328491132469758489571263843795126795612384216843579351987642628154937974236815

897625134512347689346189257673914825254876391189532476925468713438751962761293548
897625134512347689346189257673914825254876391189532476925468713438751962761293548
*/