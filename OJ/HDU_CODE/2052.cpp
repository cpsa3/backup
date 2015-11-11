////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-30 13:20:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,m,i,j;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("+");
		for(i=1;i<=m;i++)
			printf("-");
		printf("+\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m+2;j++)
			{
				if(j==1||j==m+2)
					printf("|");
				else
				printf(" ");
			}
			printf("\n");
		}
		printf("+");
		for(i=1;i<=m;i++)
			printf("-");
		printf("+\n\n");
	}
return 0;
}