////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 14:00:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int n,p,o,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&p,&o);
		int s=0;
		if(n>6)
			s=(n-6)*8+27;
		else
			for(i=1,j=7;i<=n;i++,j--)
				s+=j;
			if(s+p>=o)
				printf("Yes\n");
			else
				printf("No\n");
	}
return 0;
}