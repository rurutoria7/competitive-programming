#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

double calc(vector<double> const &f, double x)
{
    double res = 0;
    for (int i=0,j=f.size()-1; i<f.size(); i++,j--)
    {
        res += pow(x,j)*f[i];
    }
    return res;
}

vector<double> wei (vector<double> const &f)
{
    vector<double> res;
    for (int i=0,j=f.size()-1; i<f.size()-1; i++,j--)
    {
        res.pb(j*f[i]);
    }
    return res;
}

vector<double> f, fw;

signed main()
{
    double x;
    while (cin >> x) f.pb(x);
    fw = wei(f);


    double x0 = 0;
    while(1)
    {
        double x1 = x0 - calc(f,x0)/calc(fw,x0);
        if (abs(calc(f,x1)) < 1e-4)
        {
            cout << fixed << setprecision(2) << x1 << endl;
            break;
        }
        x0 = x1;
    }
}