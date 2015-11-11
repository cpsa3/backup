////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 10:37:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[2000];
main ()
{
	int n,max,count,k,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		count=0;
		k=n;
		while(k)
		{
			count++;
			max=30001;
			for(i=1;i<=n;i++)
			{
				if(a[i]!=-1&&a[i]<=max)
				{
					k--;
					max=a[i];
					a[i]=-1;
				}
			}
		}
		printf("%d\n",count);
	}
return 0;
}