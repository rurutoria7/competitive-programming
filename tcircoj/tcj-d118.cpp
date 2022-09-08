#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <map>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
/*
轉移來源的結束時間必須小於現在的開始時間
按照結束時間排序，比我晚結束的不可能是我的轉移來源
比我早結束的，必須找到比我的開始時間還要早的轉移來源
如果越晚結束，那就必須值越大，否則不會是轉移來源
維護可能的轉移來源，盡可能選晚一點結束的（小於中最晚的）
*/

const int N = 1e5+10;
int n, id[N], op[N], ed[N], w[N];
map<int,int> dp;

int cmp (int i, int j){
    return ed[i] < ed[j];
}

signed main(){
    minamisan
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> op[i] >> ed[i] >> w[i], id[i] = i;
    }
    sort(id+1,id+1+n,cmp);
    for (int i=1; i<=n; i++){   
        int x;
        if (dp.empty() || dp.begin()->ff>=op[id[i]]){
            x = w[id[i]];
        }
        else{
            auto src = --dp.lower_bound(op[id[i]]);
            x = src->ss + w[id[i]];
        }
        if (dp.empty() || x>dp.rbegin()->ss){
            dp[ed[id[i]]] = x;
        }
    }
    cout << dp.rbegin()->ss << '\n';
}