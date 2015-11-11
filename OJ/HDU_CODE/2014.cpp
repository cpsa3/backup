////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-19 09:23:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,t;
	while(scanf("%d",&n)!=EOF)
	{
		int max,min,sum;
		scanf("%d",&t);
		max=min=sum=t;
		for(i=1;i<=n-1;i++)
		{
			scanf("%d",&t);
			if(max<t)
				max=t;
			if(min>t)
				min=t;
			sum+=t;
		}
		double v;
		v=(sum-min-max)*1.0/(n-2);
		printf("%.2lf\n",v);
	}
return 0;
}