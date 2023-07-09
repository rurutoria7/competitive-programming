#include <stdio.h>
#include <stdlib.h>

signed main()
{
    int owo, qwq = 0;
    scanf("%d", &owo);
    while (owo)
    {
        qwq = qwq*10 + owo%10;
        owo/=10;
    }
    printf("%d\n", qwq);
}