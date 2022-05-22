#include <iostream>
#define int long long
using namespace std;

signed main()
{
    string s;
    cin >> s;
    s += '@';

    int mxlen = 0, curlen = 0;
    for (int i=0; i<s.size(); i++)
    {
        if (i>0 && s[i]!=s[i-1])
        {
            mxlen = max(mxlen, curlen);
            curlen = 0;
        }
        curlen++;
    }
    cout << mxlen << '\n';
}