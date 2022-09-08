#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, j, k) for (int i=j; i<=k; i++)

const int N = 20;

char s1[N], s2[N], s3[N];

char* add (char *a, char *b)
{
    char *p = (char*)malloc((strlen(a)+strlen(b))*sizeof(char));
    memcpy(p, a, strlen(a));
    memcpy(p+strlen(a), b, strlen(b));
    return p;
}

signed main()
{
    scanf("%s%s", s1, s2);
    printf("%s\n", add(s1, s2));
}