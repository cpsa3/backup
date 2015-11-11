////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-10 22:24:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2568
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		while(n)
		{
			if(n%2!=0)
			{n--;sum++;}
			else
				n/=2;
		}
		printf("%d\n",sum);
	}
return 0;
}