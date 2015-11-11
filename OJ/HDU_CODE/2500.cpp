////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 19:24:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2500
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n,i,j;
	char a[4]={'H','D','U','\0'};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n*3;i++)
		{
			for(j=1;j<=n;j++)
				printf("%s",a);
			printf("\n");
		}
	}
return 0;
}