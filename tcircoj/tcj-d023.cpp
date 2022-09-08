#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <map>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define int long long
#define pb push_back
#define ff first
#define ss second
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

map<pii,pii> cups; // {l wall id, r wall id}, {cap, size}

int n, ijpos, ijwat, h[N];

pair<pii,pii> cupmerge (pair<pii,pii> x, pair<pii,pii> y){
    return {
        {x.ff.ff,y.ff.ss},
        {min(h[x.ff.ff],h[y.ff.ss])*(y.ff.ss-x.ff.ff), x.ss.ss+y.ss.ss}
    };
}

void fill (map<pii,pii>::iterator c, int wat){
    int lid = c->ff.ff;
    int rid = c->ff.ss;
    int &cap = c->ss.ff;
    int &siz = c->ss.ss;

    if (wat <= cap-siz){
        siz += wat;
    }
    else{
        wat -= cap-siz;
        siz = cap;
        auto go = (h[lid]<h[rid]? prev(c):next(c));

        if (go->ss.ff == go->ss.ss){
            pair<pii,pii> ncup = h[lid]<h[rid]? cupmerge(*go,*c):cupmerge(*c,*go);
            cups.erase(c);
            cups.erase(go);
            go = cups.insert(ncup).ff;
        }
        fill(go,wat);
    }
    
}

signed main(){
    minamisan
    cin >> n >> ijpos >> ijwat, ijpos++; //ijpos: left
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    // build cups
    for (int i=1; i<n; i++){
        cups.insert({{i,i+1}, {min(h[i],h[i+1]),0}});
    }
    fill(cups.lower_bound({ijpos,ijpos+1}), ijwat);
    //turn to final 
    for (auto c: cups){
        for (int i=c.ff.ff; i<c.ff.ss; i++){
            cout << c.ss.ss/(c.ff.ss-c.ff.ff) << ' ';
        }
    }

    cout << '\n';
}