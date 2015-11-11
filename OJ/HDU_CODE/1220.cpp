////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 14:07:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1220
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int n,m,k;
	while(scanf("%d",&n)!=EOF)
	{
		m=n*n*n;
		k=m*(m-1)/2-(6*m-6*n*n)/2;
		printf("%d\n",k);
	}
return 0;
}