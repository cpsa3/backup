////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-09 23:11:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:4964KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define N 1100
#define max 999999
int g[N][N],S[N],D[N];
int dijkstra(int s,int n)
{
	int i,j,u,min,dis[N],mark[N];
	for(i=0;i<n;i++)
	{
		mark[i]=0;
		dis[i]=g[s][i];
	}
	mark[s]=1;
	dis[s]=0;
	for(i=1;i<n;i++)
	{
		min=max;
		for(j=0;j<n;j++)
			if(!mark[j]&&min>dis[j])
			{
				u=j;
				min=dis[j];
			}
		mark[u]=1;
		for(j=0;j<n;j++)
			if(!mark[j]&&g[u][j]!=max&&dis[j]>dis[u]+g[u][j])
				dis[j]=dis[u]+g[u][j];
	}
	min=max;
	for(i=0;i<n;i++)
		if(D[i])
			if(min>dis[D[i]])
				min=dis[D[i]];
	return min;
}
int main()
{
	int i,j,t,s,d,x,y,dis,n;
	while(scanf("%d%d%d",&t,&s,&d)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			S[i]=0;D[i]=0;
			for(j=0;j<N;j++)
				g[i][j]=max;
		}
		n=0;
		while(t--)
		{
			scanf("%d%d%d",&x,&y,&dis);
			if(g[x-1][y-1]>dis)
				g[x-1][y-1]=g[y-1][x-1]=dis;
			if(n<x)
				n=x;
			if(n<y)
				n=y;
		}
		for(i=0;i<s;i++)
		{
			scanf("%d",&S[i]);
			S[i]--;
		}
		for(i=0;i<d;i++)
		{
			scanf("%d",&D[i]);
			D[i]--;
		}
		dis=max;
		for(i=0;i<s;i++)
		{
			y=dijkstra(S[i],n);
			//printf("%d,%d distance is %d\n",S[i],D[j],y);
			if(dis>y)
				dis=y;
		}
		printf("%d\n",dis);
	}
	return 0;
}
