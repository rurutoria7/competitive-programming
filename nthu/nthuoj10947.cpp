#include <stdio.h>
#define N (10000000)

int n, m, nex[N], val[N], cnt, x;

signed main()
{
	while (scanf("%d", &x) && x != -1)
		nex[cnt] = cnt + 1, val[++cnt] = x;
	while (scanf("%d", &x) && x != -1)
		for (int prev=0, cur=nex[0], i=1; cur; prev=cur, cur=nex[cur], i++)
			if (i == x)
				nex[prev] = nex[cur];	
	for (int cur=nex[0]; cur; cur=nex[cur])
		printf("%d ", val[cur]);
	printf("\n");
}
