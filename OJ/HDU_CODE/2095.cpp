////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-12 18:19:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,w,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int s=0;
		for(i=1;i<=n;i++)
		{
		scanf("%d",&w);
		s^=w;
		}
		printf("%d\n",s);
	}
return 0;
}