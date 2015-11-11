////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-01 20:30:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1498
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:276KB
//////////////////System Comment End//////////////////
/*二分图的最小点覆盖=最大匹配*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 205
using namespace std;
int G[105][105];
bool map[105][105],flag[105],kind[55];
int result[105];
int W[55],cnt;
int N,K;
void Init()
{
	int i,j;
	memset(kind,false,sizeof(kind));
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&G[i][j]);
			kind[G[i][j]]=true;
		}
	}
}
int Find(int a)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(map[a][i]&&!flag[i])
		{
			flag[i]=true;
			if(result[i]==-1||Find(result[i]))
			{
				result[i]=a;
				return 1;
			}
		}
	}
	return 0; 
}
int MaxMatch()
{
	int i,ans=0;
	for(i=1;i<=N;i++)
	{
		memset(flag,false,sizeof(flag));
		ans+=Find(i); 
	}
	return ans; 
}
void Build(int x)
{
	int i,j;
	memset(map,false,sizeof(map));
	memset(result,-1,sizeof(result));
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(G[i][j]==x)
				map[i][j]=true;
		}
	}
}
void Solve()
{
	int i,j;
	cnt=0;
	for(i=1;i<=50;i++)
	{
		if(kind[i])
			W[cnt++]=i;
	}
	int ans_id[55],ans_n=0;
	for(i=0;i<cnt;i++)
	{
		Build(W[i]);
		if(MaxMatch()>K)
			ans_id[ans_n++]=W[i];
	}
	if(!ans_n)
		printf("-1\n");
	else
	{
		for(i=0;i<ans_n-1;i++)
			printf("%d ",ans_id[i]);
		printf("%d\n",ans_id[i]);
	}
}
int main()
{
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		if(N==0&&K==0) break;
		Init();
		Solve();
	}
return 0;
}