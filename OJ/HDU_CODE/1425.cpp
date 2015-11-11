////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 20:43:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:2152KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int cmp(const void *x,const void *y)
{
	return *((int *)y)-*((int *)x);
}
int a[1000010]={0};
main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		for(i=1;i<m;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
return 0;
}