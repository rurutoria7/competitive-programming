#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> pii;

const int N = 3e5+1;

int n, m, k, rs[N];
vector<vector<int>> cs;

signed main(){
    minamisan
    cin >> k >> m >> n;
    cs = vector<vector<int>>(m+1,vector<int>(n+1,0));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> cs[i][j];
        }
    }

    // build cs[i][j]: a[1][j] + ... + a[i][j]
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cs[i][j] += cs[i-1][j];
        }
    }
    // enum u, d
    set<int> s;
    int ans = 0;
    for (int u=1; u<=m; u++){
        for (int d=u; d<=m; d++){
            // for every s[i], find best s[j], update answer
            for (int i=1; i<=n; i++){
                rs[i] = rs[i-1] + cs[d][i] - cs[u-1][i];
            }
            s.clear(), s.insert(0);
            for (int i=1; i<=n; i++){
                auto j = s.lower_bound(rs[i]-k);
                if (j != s.end()){
                    ans = max(ans, rs[i]-*j);
                }
                s.insert(rs[i]);
            }
        }
    }
    cout << ans << '\n';
}