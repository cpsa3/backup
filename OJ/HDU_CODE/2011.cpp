////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-19 09:09:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int m,n;
	while(scanf("%d",&m)!=EOF)
	{
		while(m--)
		{
			scanf("%d",&n);
			int i,t;
			double w;
			for(i=1,t=1,w=0;i<=n;i++)
			{
				w+=1.0/i*t;
				t=-t;
			}
			printf("%.2lf\n",w);
		}
	}
return 0;
}