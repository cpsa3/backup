////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-16 14:55:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <math.h>
using namespace std;
main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		double s,t;
		for(i=2,s=n,t=n;i<=m;i++)
		{
			t=sqrt(t);
			s+=t;
			
		}
		printf("%.2lf\n",s);
	}
return 0;
}