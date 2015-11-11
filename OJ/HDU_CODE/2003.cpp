////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 23:05:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2003
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	double w;
	while(scanf("%lf",&w)!=EOF)
	{
		if(w<0)
			w=-w;
		printf("%.2lf\n",w);
	}
return 0;
}