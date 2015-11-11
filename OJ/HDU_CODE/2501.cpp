////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 19:30:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2501
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[31];
main ()
{
	int t,i,n;
	f[1]=1;f[2]=3;
	for(i=3;i<=30;i++)
		f[i]=f[i-1]+2*f[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);	
	}
return 0;
}