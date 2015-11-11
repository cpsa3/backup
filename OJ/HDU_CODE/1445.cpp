////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-23 10:35:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1445
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
using  namespace std;
main ()
{
	int n,i,v,t;
	double min;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		min=9999999;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&v,&t);
			if(t>=0)
			{
				if(t+4.5/v*3600<min)//πÿº¸
					min=t+4.5/v*3600;
			}
		}
		printf("%d\n",(int)(min+0.9999));
	}
return 0;
}