////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-05 19:25:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[51];
main ()
{
	int i,n;
	f[0]=0;f[1]=1;
	for(i=2;i<=50;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		printf("%I64d\n",f[n]);
	}
return 0;
}