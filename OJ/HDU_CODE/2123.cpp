////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-08 15:54:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2123
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int map[10][10];
main ()
{
	int i,j,t,n;
	//memset(map,1,sizeof(map));
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			map[i][j]=i*j;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<n;j++)
					printf("%d ",map[i][j]);
				printf("%d\n",map[i][j]);
			}
		}
return 0;
}