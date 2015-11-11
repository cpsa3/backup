////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 11:11:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,max,w;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d",&max);
		for(i=2;i<=n;i++)
		{
			scanf("%d",&w);
			if(max<w)
				max=w;
		}
		printf("%d\n",max);
	}
return 0;
}