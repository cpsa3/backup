////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 22:44:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:992KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[100005];
main ()
{
	__int64 i,n;
	f[0]=0;f[1]=1;f[2]=3;f[3]=30;
	for(i=4;i<=100000;i++)
	{
		if(i%3==0)
			f[i]=f[i-1]+i*i*i;
		else
			f[i]=f[i-1]+i;
	}
	while(scanf("%I64d",&n)!=EOF)
	{
		if(n<0)
			break;
		printf("%I64d\n",f[n]);
	}
return 0;
}