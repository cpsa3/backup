////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 13:05:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[51];
main ()
{
	int t,a,b,i;
	f[1]=f[2]=1;
	for(i=3;i<=50;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%I64d\n",f[b-a+1]);
	}
return 0;
}