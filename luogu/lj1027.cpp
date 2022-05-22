#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n'
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
const int N = 500;
const double EPS = 1e-3;

int t;
int n, w, op, ed;
double G[N][N];
pdd pos[N];

pdd operator + (pdd x, pdd y){
    return {x.ff+y.ff, x.ss+y.ss};
}
pdd operator - (pdd x, pdd y){
    return {x.ff-y.ff, x.ss-y.ss};
}
double operator * (pdd x, pdd y){
    return x.ff*y.ff + x.ss*y.ss;
}

pdd getp3 (pdd p1, pdd p2, pdd p3){
    pdd p4;
    if (abs((p1-p2)*(p3-p1)) < EPS){
        p4 = p1+(p2-p1)+(p3-p1);
    }
    if (abs((p1-p2)*(p2-p3)) < EPS){
        p4 = p2 + (p1-p2) + (p3-p2);
    }
    if (abs((p3-p1)*(p3-p2)) < EPS){
        p4 = p3 + (p1-p3)+(p2-p3);
    }
    return p4;
}
double dis (pdd u, pdd v, double d){
    return sqrt((u-v)*(u-v))*d;
}

signed main(){
    cin >> t;
    while (t--){
        memset(G,0x3f,sizeof(G));
        cin >> n >> w >> op >> ed;
        rep(i,1,n){
            int wi;
            rep(j,0,2) cin >> pos[i+j*n].ff >> pos[i+j*n].ss;
            cin >> wi;
            pos[i+3*n] = getp3(pos[i],pos[i+n],pos[i+2*n]);
            rep(j,0,3){
                rep(k,0,3){
                    int u = i+j*n, v = i+k*n;
                    G[u][v] = dis(pos[u], pos[v], wi);
                }
            }
        }
        rep(u,1,4*n){
            rep(v,1,4*n){
                if ((u-v)%n == 0){
                    continue;
                }
                G[u][v] = dis(pos[u], pos[v],w);
            }
        }
        rep(k,1,4*n){
            rep(i,1,4*n){
                rep(j,1,4*n){
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
        double ans = 1e20;
        rep(i,0,3){
            rep(j,0,3){
                int u = op+i*n, v = ed+j*n;
                ans = min(ans, G[u][v]);
            }
        }
        cout << fixed << setprecision(1) << ans << '\n';
    }
}