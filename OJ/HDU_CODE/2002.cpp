////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 23:03:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
#define pi 3.1415927
using namespace std;
main ()
{
	double r;
	while(scanf("%lf",&r)!=EOF)
	{
		double w;
		w=4*1.0/3*pi*r*r*r;
		printf("%.3lf\n",w);
	}
return 0;
}