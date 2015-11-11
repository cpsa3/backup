////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 22:56:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#include <stdlib.h> 
int a[510];
int cmp(const void *x,const void *y)
{
	return *((int *)x)-*((int *)y);
}
main ()
{
	int m,i,n,w,sum;
	scanf("%d",&m);
	while(m--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		if(n%2!=0)
		{
		    w=n/2+1;
			for(i=1;i<=n;i++)
				sum+=abs(a[w]-a[i]);
			printf("%d\n",sum);
		}
		else 
		{
			int sum1=0,sum2=0;
			 for(i=1;i<=n;i++)
			 {
				 sum1+=abs(a[n/2]-a[i]);
				 sum2+=abs(a[n/2+1]-a[i]);
			 }
			 if(sum1>=sum2)
				 sum=sum1;
			 else
				 sum=sum2;
			 printf("%d\n",sum);
		}
	}
	return 0;
}