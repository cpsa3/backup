////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 20:02:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int cmp(const void *x,const void *y)
{
return *((int *)x)-*((int *)y);
}
int a[20001];
main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n+m;i++)
			scanf("%d",&a[i]);
		qsort(a+1,n+m,sizeof(int),cmp);
		int flag=0;
		for(i=1;i<=n+m;i++)
		{
			if(i==1)
			{printf("%d",a[i]);continue;}
			if(i!=1&&a[i]==a[i-1])
				continue;
			printf(" %d",a[i]);
		}
		printf("\n");
	}

return 0;
}