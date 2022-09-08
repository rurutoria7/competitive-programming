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

string s;
string sol(){
    string st;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st += s[i];
        }
        else{
            if (st.empty()) return "no";
            if (s[i]==')' && st.back()!='(') return "no";
            if (s[i]=='}' && st.back()!='{') return "no";
            if (s[i]==']' && st.back()!='[') return "no";
            st.pop_back();
        }
    }
    return st.empty()? "yes":"no";
}

signed main(){
    minamisan
    while (cin >> s){
        cout << sol() << '\n';
    }
}