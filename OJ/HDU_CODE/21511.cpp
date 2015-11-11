////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-08 19:48:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2151
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[101][101];
main ()
{
	int n,p,m,t,i,j;
	while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF)
	{
		memset(f,0,sizeof(f));
		f[0][p]=1;//关键的初始化
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j-1>0)
					f[i][j]+=f[i-1][j-1];
				if(j+1<=n)
					f[i][j]+=f[i-1][j+1];
			}
		}
		printf("%d\n",f[m][t]);
	}
return 0;
}
//动态规划
//状态转移方程f[i][j]=f[i-1][j-1]+f[i-1][j+1];