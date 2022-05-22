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

string s;

void recurs(string &s, int depth)
{
    string t = s;
    if (next_permutation(s.begin(), s.end(), greater<char>()))
    {
        recurs(s,depth+1);
    }
    else
    {
        cout << depth << "\n";
    }
    cout << t << "\n";
}

signed main()
{
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    recurs(s, 1);
}