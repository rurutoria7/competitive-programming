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

int h1, m1, s1, h2, m2, s2, k;

signed main(){
    char c;
    cin >> h2 >> c >> m2 >> c >> s2;
    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> k;

    s1 -= s2;
    while (s1 < 0) s1 += 60, m1 -= 1;
    m1 -= m2;
    while (m2 < 0) m1 += 60, h1 -= 1;
    h1 -= h2;
    
    int sum = h1*60*60 + m1*60 + s1;
    cout << sum*k << '\n';
}