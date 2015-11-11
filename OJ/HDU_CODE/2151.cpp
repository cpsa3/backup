////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-08 19:45:22
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
		f[m][t]=1;//关键的初始化
		for(i=m-1;i>=0;i--)
		{
			for(j=1;j<=n;j++)
			{
				if(j-1>0)
					f[i][j]+=f[i+1][j-1];
				if(j+1<=n)
					f[i][j]+=f[i+1][j+1];
			}
		}
		printf("%d\n",f[0][p]);
	}
return 0;
}