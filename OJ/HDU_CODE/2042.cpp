////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 13:40:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,s;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&s);
		int w=3;
		for(i=1;i<=s;i++)
			w=w*2-2;
		printf("%d\n",w);
	}
return 0;
}