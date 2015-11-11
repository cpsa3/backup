////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-10 23:40:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3339
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:312KB
//////////////////System Comment End//////////////////
/*AC代码：187ms*/
/*最短路+01背包*/
#include <iostream>
#define MAXN 105
#define INF 99999999
#define min(a,b) (a<b?a:b)
int path[MAXN];
int map[MAXN][MAXN];
int mark[MAXN];
int V[MAXN];
int f[20000];//每个pow最大为100，最多有100个，所以要开10000以上
int N,M,sum;
void Init()
{
	int i,j,s,e,d;
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
			map[i][j]=INF;
		path[i]=INF;
		map[i][i]=0;
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d",&s,&e,&d);
		if(map[s][e]>d)
			map[s][e]=map[e][s]=d;
	}
	for(i=1,sum=0;i<=N;i++)
	{
		scanf("%d",&V[i]);
		sum+=V[i];
	}
	/*
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	*/

}
void Floyd()
{
	int i,j,k;
	for(k=0;k<=N;k++)
	{
		for(i=0;i<=N;i++)
		{
			if(k==i) continue;
			for(j=0;j<=N;j++)
			{
				if(j==k||i==j||map[i][k]==INF||map[k][j]==INF) 
					continue;
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		Init();
		Floyd();
		for(i=1;i<=sum;i++)
			f[i]=INF;
		f[0]=0;
		/*
		for(i=1;i<=N;i++)
			printf("*%d ",map[0][i]);
		printf("\n");
		*/
		for(i=1;i<=N;i++)
		{
			for(j=sum;j>=V[i];j--)
			{
				if(map[0][i]+f[j-V[i]]<f[j])
					f[j]=map[0][i]+f[j-V[i]];
			}
		}
		int flag=0;
		int ans=INF;
		for(i=sum/2+1;i<=sum;i++)
			if(f[i]<ans)//注意WA了好几次
			{
				ans=f[i];
				flag=1;
			}
			if(!flag)
				printf("impossible\n");
			else
				printf("%d\n",ans);
	}
return 0;
}