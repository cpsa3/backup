////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 18:47:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,a,b,c;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&a,&b);
			a%=100;
			b%=100;
			c=a+b;
			c%=100;
			printf("%d\n",c);
		}
	}
return 0;
}