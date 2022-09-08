#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int n, m;
multiset<int> pq;

signed main(){
    cin >> n >> m;
    while (m--){
        pq.insert(0);
    }
    while (n--){
        int t;
        cin >> t;
        pq.insert(*pq.begin() + t);
        pq.erase(pq.begin());
    }
    cout << *pq.rbegin() << '\n';
}