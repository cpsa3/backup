////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-10 21:40:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,i,n,m,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int sum=0;
		for(i=1;i<=n*m;i++)
		{
			scanf("%d",&w);
			if(w)
				sum++;
		}
		printf("%d\n",sum);
	}
return 0;
}