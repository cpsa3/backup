////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 15:37:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 f[41][2];
main ()
{
	int i,n;
	f[1][0]=1;f[1][1]=2;
	f[2][0]=2;f[2][1]=6;
	for(i=3;i<=40;i++)
	{
		f[i][0]=f[i-1][1];
		f[i][1]=f[i-1][0]*2+f[i-1][1]*2;
	}
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n][0]+f[n][1]);
return 0;
}