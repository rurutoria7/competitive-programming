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

int q, n;

void get_len (int x, int &len, int &rest)
{
	int t, i;
	for (t=9,i=1; x>t*i; x-=t*i,t*=10,i++);
	len = i, rest = x;
}
int get_digit (int num, int len, int pos)
{
	rep(i,1,len-pos) num/=10;
	return num%10;
}
int qpow (int i, int j)
{
	int res = 1;
	for (; j; j>>=1,i*=i)
		if (j&1)
			res *= i;
	return res;
}

signed main()
{
	liyuu_my_wife
	cin >> q;
	while (q--)
	{
		cin >> n;
		int len, rest, pos, num;
		get_len(n,len,rest);
		pos = (rest-1)%len+1;
		num = qpow(10,len-1)+(rest-1)/len;
	//	de(len), de(rest), de(pos), de(num), dd
		cout << get_digit(num,len,pos) << '\n';
	}	
}