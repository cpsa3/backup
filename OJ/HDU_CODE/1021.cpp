////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 13:20:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			printf("no\n");
		else 
		{
			if(n%8==2||n%8==6)
				printf("yes\n");
			else printf("no\n");
		}
	}
return 0;
}