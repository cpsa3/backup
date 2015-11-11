////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-15 02:30:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3768
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:5980KB
//////////////////System Comment End//////////////////
/*枚举+SPFA预处理*/
/*一开始把SPFA写错了，郁闷*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <algorithm>
#define MAXN 100007
#define INF 1e14
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
	__int64 w;
}E[300000];
int head[MAXN],ecnt; 
int N,M,S; 
__int64 map[20][20];//存放预处理出来的最短路
int id[20],num[20];
bool vis[MAXN];
__int64 dis[MAXN],ans;
queue<int>Q;

void Insert(int u,int v,__int64 w)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void Init()
{
	int i,u,v;
	__int64 w;
	memset(head,-1,sizeof(head));ecnt=0;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%I64d",&u,&v,&w);
		Insert(u,v,w);
		Insert(v,u,w);
	}
	scanf("%d",&S);
	for(i=1;i<=S;i++)
		scanf("%d",&id[i]);
	id[0]=0;
}
void SPFA(int s,int ith)
{
	int i,u,v;
	__int64 w;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=0;i<=N;i++)
		dis[i]=INF;
	Q.push(s);
	vis[s]=true;
	dis[s]=0;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;//一开始这里漏泄了，WA了好几次
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;w=E[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
	for(i=0;i<=S;i++)
		map[ith][i]=dis[id[i]];
}
void Run()
{
	int i;
	for(i=0;i<=S;i++)
	{
		SPFA(id[i],i);
	}
}
void dfs(int num[],int cnt,bool vis[],__int64 len)
{
	int i;
	if(len>=ans) return; 
	if(cnt==S) 
	{ 
		ans=min(ans,len+map[num[S]][0]);
		return ;
	}
	for(i=1;i<=S;i++)
	{
		if(!vis[i])
		{
			vis[i]=true; 
			num[++cnt]=i;
			dfs(num,cnt,vis,len+map[num[cnt-1]][num[cnt]]);
			cnt--;
			vis[i]=false;  
		}
	}
}
void Solve()
{
	Run();//预处理
	ans=INF;
	//暴力枚举
	memset(vis,false,sizeof(vis));
	num[0]=id[0];
	vis[0]=true;
	dfs(num,0,vis,0);
	printf("%I64d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}
/*
6 7
0 1 1
1 2 1
1 3 1
2 4 1
0 4 1
0 5 1
3 5 1

*/