#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx_my_wife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string color (int k)
{
    if (k >= 3000) return "Legendary grandmaster";
    if (k >= 2600) return "International grandmaster";
    if (k >= 2400) return "Grandmaster";
    if (k >= 2300) return "International master";
    if (k >= 2100) return "Master";
    if (k >= 1900) return "Candidate master";
    if (k >= 1600) return "Expert";
    if (k >= 1400) return "Specialist";
    if (k >= 1200) return "Pupil";
    return "Newbie";
}

signed main()
{
    int t, n, k;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n)
        {
            int x;
            cin >> x;
            string ori = color(k);
            string nw = color(k+=x);
            if (ori != nw)
            {
                cout << ori << " -> " << nw << endl;
            }
        }
        cout << color(k) << endl;
    }
}