#include <stdio.h>
#include <stdlib.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define N 100
#define M 100

int q;
char s[N];

int main()
{
    scanf("%s%d", s, &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int i=l, j=r; l<r; l++, r--)
        {
            char tmp;
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        printf("%s\n", s);        
    }
}