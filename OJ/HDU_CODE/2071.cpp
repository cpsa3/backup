////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 23:26:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int i,n,m;
	double w,MAX;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		scanf("%lf",&w);
		MAX=w;
		for(i=2;i<=m;i++)
		{
			scanf("%lf",&w);
			if(MAX<w)
				MAX=w;
		}
		printf("%.2lf\n",MAX);
	}
return 0;
}