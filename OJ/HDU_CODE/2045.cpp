////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 15:25:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 f[51];
main ()
{
	int n,i;
	f[1]=3;f[2]=6;f[3]=6;
	for(i=4;i<=50;i++)
		f[i]=f[i-1]+2*f[i-2];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
return 0;
}