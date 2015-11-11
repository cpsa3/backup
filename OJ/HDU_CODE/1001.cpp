////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 09:54:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
using  namespace std;
main ()
{
	int n,i,s;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1,s=0;i<=n;i++)
			s+=i;
		printf("%d\n\n",s);
	}
return 0;
}