////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 22:41:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[21][2];
main ()
{
	int i,t,n;
	f[1][0]=1;f[1][1]=2;f[2][0]=3;f[2][1]=4;
	for(i=3;i<=20;i++)
	{
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=(3*f[i-1][0]+2*f[i-1][1])-f[i][0];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%I64d\n",f[n][0]+f[n][1]);
	}
return 0;
}