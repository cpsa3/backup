////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-30 20:36:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1559
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:4132KB
//////////////////System Comment End//////////////////
#include <iostream>
int v[1001][1001];
main ()
{
	int T,n,m,x,y,s,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&m,&n,&x,&y);
		for(i=1;i<=m;i++)
		{
			for(j=1,s=0;j<=n;j++)
			{
				scanf("%d",&v[i][j]);
				s+=v[i][j];
				v[i][j]=s;
				if(i>1)
					v[i][j]+=v[i-1][j];
			}
		}
		int max=0;
		for(i=1;i<=m;i++)
		{
			if(i+x-1>m)
				break;
			for(j=1;j<=n;j++)
			{
				if(j+y-1>n)
					break;
				int w=v[i+x-1][j+y-1];
				if(i>1) w-=v[i-1][j+y-1];
				if(j>1) w-=v[i+x-1][j-1];
				if(i>1&&j>1) w+=v[i-1][j-1];
				if(max<w)
					max=w;
			}
		}
		printf("%d\n",max);
	}
return 0;
}