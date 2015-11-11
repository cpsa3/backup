////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 23:27:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,w,i,a;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1,a=1;i<=n;i++)
		{
			scanf("%d",&w);
			if(w%2!=0)
				a*=w;
		}
		printf("%d\n",a);
	}
return 0;
}