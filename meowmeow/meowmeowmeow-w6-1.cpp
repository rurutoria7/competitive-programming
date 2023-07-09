#include<bits/extc++.h>
#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define roadroller ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;

const int N = 6;

int a[N+5][N+5], cnt[200];

inline string read()
{
	int x;
	string res;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			cin >> x;
			res += (char)(x == 0? '*' : x + '0' - 1);
			cnt[res.back()]++;
		}
	}
	return res;
}

inline int is_ed(string s)
{
	return s[16] == s[17] && s[17] == '0';
}

int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline string move(string s, int pos, int fw)
{
	if (s[pos] == '*') return "";
	int r = pos/N, c = pos%N;
	for (int i=0; i<=cnt[s[pos]]; i++)
	{
		int nr = r + step[fw][0]*i, nc = c + step[fw][1]*i;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			break;
		char &c = s[nr * N + nc];
		if (i >= cnt[s[pos]])
		{
			if (c == '*')
			{
				swap(c, s[pos]);
				return s;
			}
			else break;
		}
		else if (c != s[pos])
			break;
	}
	return "";
}



inline int bfs(string op)
{
	queue<string> q;	
	gp_hash_table<string, int> dis;

	dis[op] = 2;
	q.push(op);

	while (q.size())
	{
		 string u = q.front();
		 int d = dis[u];
		 q.pop();

		 if (d > 10) break;
		 if (is_ed(u)) return d;

		 for (int i=0; i<N*N; i++)
		 {
			 for (int fw=0; fw<4; fw++)
			 {
				string v = move(u,i,fw);
				if (v.size()==0 || dis[v] > 0) continue;
				dis[v] = d + 1;
				q.push(v);
			 }
		 }
	}

	return -1;
}

signed main()
{
	string op = read();
	cout << bfs(op) << '\n';
}

/*
2 2 0 0 0 7
3 0 0 5 0 7
3 1 1 5 0 7
3 0 0 5 0 0
4 0 0 0 8 8
4 0 6 6 6 0

0 2 0 6 6 0
0 2 0 0 7 0
0 3 1 1 7 0
0 3 4 4 8 0
0 5 5 5 8 0
0 0 0 0 0 0
   */
