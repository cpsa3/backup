////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 14:34:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		printf("%d\n",3*m*(m-1)+2);
	}
return 0; 
}