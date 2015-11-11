////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:31:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int a[10010]={0};
int cmp(const void *x,const void *y)
{
	return *((int *)x)-*((int *)y);
}
main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		printf("%d\n",a[n/2+1]);
	}
return 0;
}