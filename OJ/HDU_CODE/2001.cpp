////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 22:59:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
main ()
{
	double x1,y1,x2,y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		double w;
		w=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.2lf\n",w);
	}
return 0;
}