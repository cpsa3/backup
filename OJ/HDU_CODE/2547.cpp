////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-23 19:47:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2547
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	int t;
	double a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		double w=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		printf("%.1lf\n",w);
	}
return 0;
}