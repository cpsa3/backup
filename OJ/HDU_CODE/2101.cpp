////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 11:05:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if((a+b)%86==0)
			printf("yes\n");
		else 
			printf("no\n");
	}
return 0;
}