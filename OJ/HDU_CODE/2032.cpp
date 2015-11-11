////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 18:56:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int w[31][31]={0},i,n,j;
	for(i=1;i<=30;i++)
	{
		w[i][i]=1;
		w[i][1]=1;
	}
	for(i=3;i<=30;i++)
		for(j=2;j<i;j++)
			w[i][j]=w[i-1][j-1]+w[i-1][j];
		while(scanf("%d",&n)!=EOF)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<i;j++)
					printf("%d ",w[i][j]);
				printf("%d\n",w[i][j]);
			}
			printf("\n");
		}
return 0;
}