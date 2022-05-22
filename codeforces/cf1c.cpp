/*
10.38
面積最小的正多邊形，頂點包含這三個點
檢查可否行成 i 個點的多邊形
 */
#include <bits/stdc++.h>
#define int long long 
#define double long double
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define minamisan ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,double> vec;

const double PI = acos(-1), EPS = 1e-6;

vec a, b, c;

vec operator - (const vec x, const vec y){
	return {x.ff-y.ff,x.ss-y.ss};
}
double abs (vec x){
	return x.ff*x.ff + x.ss*x.ss;
}
double ysdl (double x, double y, double z){
	return (x+y-z)/(2*sqrt(x)*sqrt(y));
}

inline int fequal(double a,double b){
    return fabs(a-b)<=0.05;
    //题目要求是100边形以下，最小gcd弧度应为2*Pi/100=0.0628，过高精度会引起误差
}
double fgcd(double x,double y){
    if(fequal(y,0.0))//这里多了一个分号
        return x;
        //避免除零
    if(fequal(x,0.0))
        return y;
 
    return fgcd(y,fmod(x,y));
}

signed main(){
	cin >> a.ff >> a.ss;
	cin >> b.ff >> b.ss;
	cin >> c.ff >> c.ss;
	
	double A = abs(b-c), B = abs(c-a), C = abs(a-b);	
	de(A), de(B), de(C), dd
	double rad = sqrt(A)/sqrt(1.0-ysdl(C,B,A)*ysdl(C,B,A))/2;
	double r1 = acos(ysdl(A,B,C))*2;
	double r2 = acos(ysdl(A,C,B))*2;
	double r3 = 2*PI - r1 - r2;
	de(rad), de(r1), de(r2), de(r3), dd;
	de(ysdl(A,B,C)), de(ysdl(B,C,A)), de(ysdl(C,A,B)), dd
	double unit = fgcd(fgcd(r1,r2),r3);
	double ans = rad*rad*sin(unit)*round(2*PI/unit)/2;
	cout <<fixed << setprecision(7) <<  ans << '\n';
}

