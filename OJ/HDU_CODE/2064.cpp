////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:05:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 f(int n)
{
	if(n==1) return 2;
	return 3*f(n-1)+2;
}
main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f(n));
return 0;
}