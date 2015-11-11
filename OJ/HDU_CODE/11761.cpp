////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-30 15:47:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4524KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int f[11][100001];
int Max(int a,int b)
{
	return a>b?a:b;
}
main ()
{
	int n,i,j,x,t;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(f,0,sizeof(f));
		int max1=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&t);
			f[x][t]++;
			if(t>max1)
				max1=t;//记录最晚时间
		}
		for(i=max1;i>=1;i--)
		{
			for(j=0;j<=10;j++)
			{
				if(j==0)
					f[j][i]+=Max(f[j][i+1],f[j+1][i+1]);
				else if(j==10)
					f[j][i]+=Max(f[j][i+1],f[j-1][i+1]);
				else
					f[j][i]+=Max(Max(f[j-1][i+1],f[j+1][i+1]),f[j][i+1]);
			}
		}
		int M=0;
		for(i=4;i<=6;i++)
		{
			if(f[i][1]>M)
				M=f[i][1];
		}
		printf("%d\n",M);
	}
	return 0;
}