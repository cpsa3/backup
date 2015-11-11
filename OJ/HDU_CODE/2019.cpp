////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 15:40:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
int a[102]; 
int cmp(const void *x,const void *y)
{
return *((int *)x)-*((int *)y);
}
main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[i]=m;
		qsort(a,n+1,sizeof(int),cmp);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
return 0;
}