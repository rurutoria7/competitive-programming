#include <stdio.h>
#include <stdlib.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define int long long

const int N = 1e5+10;

int arr[100005], n, qry[100005], q;

signed cmp (const void *x, const void *y)
{
    if (*(int*)x < *(int*)y) return 1;
    else if (*(int*)x == *(int*)y) return 0;
    else return -1;
}

signed main()
{
    scanf("%lld", &n);
    rep(i,1,n) scanf("%lld", arr+i);
    scanf("%lld", &q);
    rep(i,1,q) scanf("%lld", qry+i);

    qsort(arr+1, n, sizeof(arr[0]), cmp);


    for (int j=1, i=0; j<=q; j++)
    {
        while (i<n && arr[i+1] > qry[j])
            i++;
        printf("%lld\n", n-i);
    }
}