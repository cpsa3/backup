////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-12 15:48:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
int  f(int n)
{
	int i;
	if(n==1)
		return 0;
	for(i=2;i<n;i++)
		if(n%i==0)
			break;
		if(i==n)
			return 1;
		return 0;
}

main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		int l=n/2;
		for(i=l;i>=1;i--)
		{
			if(f(i)&&f(n-i))
			{printf("%d %d\n",i,n-i);break;}
		}
	}
	return 0;
}