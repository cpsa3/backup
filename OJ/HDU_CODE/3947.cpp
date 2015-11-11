////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 00:45:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3947
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:364KB
//////////////////System Comment End//////////////////
/*流量不等式建图,最小费用最大流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>
#define MAXN 2005
#define INF 1e8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,c,next;
}E[2000000];
int head[MAXN],ecnt;
int fa[MAXN],W[MAXN],sum[MAXN],Total;
bool vis[MAXN];
int dis[MAXN],pre[MAXN];
int N,M,cas,scr,sink,vn;

void Insert(int u,int v,int w,int c)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].c=c;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
	E[ecnt].u=v;
	E[ecnt].v=u;
	E[ecnt].w=0;
	E[ecnt].c=-c;
	E[ecnt].next=head[v];
	head[v]=ecnt++;
}
void Init()
{
	int i,u,v,w,c;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(sum,0,sizeof(sum));
	scanf("%d",&N);
	for(i=1;i<N;i++)
	{
		scanf("%d%d",&u,&v);
		fa[u]=v; 
		scanf("%d",&W[u]);//注意
	}
	scanf("%d",&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d%d",&u,&v,&w,&c);
		Insert(u,v,w,c); 
	}
	for(i=2;i<=N;i++)
		Insert(fa[i],i,INF,0);
	for(i=2;i<=N;i++)
		sum[fa[i]]+=W[i];
	W[1]=0;
	scr=0;sink=N+1;vn=sink+1;
	Total=0;
	for(i=1;i<=N;i++)
	{
		if(sum[i]<W[i])
		{
			Insert(scr,i,W[i]-sum[i],0);
			Total+=W[i]-sum[i];
		}
		else if(sum[i]>W[i])
			Insert(i,sink,sum[i]-W[i],0);
	}
}
queue<int>Q;
bool SPFA(int s,int t,int n)
{
	int i,u,v;
	int c;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=0;i<=n;i++)//找最长路
		dis[i]=INF;
	Q.push(s);
	pre[s]=-1;
	dis[s]=0;
	vis[s]=true;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;c=E[i].c;
			if(E[i].w>0&&dis[v]>dis[u]+c)
			{
				dis[v]=dis[u]+c;
				pre[v]=i;
				if(!vis[v])
				{
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
	if(dis[t]!=INF) return true;
	return false;
}
void Solve()
{
	int i,ans=0,flow,Max_flow=0;
	while(SPFA(scr,sink,vn))
	{
		flow=INF;
		for(i=pre[sink];i!=-1;i=pre[E[i].u])//更新
			flow=min(flow,E[i].w);
		for(i=pre[sink];i!=-1;i=pre[E[i].u])//更新
		{
			E[i].w-=flow;
			E[i^1].w+=flow;
			//ans+=E[i].c*flow;
		}
		ans+=dis[sink]*flow;
		Max_flow+=flow; 
	} 
	if(Max_flow<Total) ans=-1;
	printf("Case #%d: %d\n",cas++,ans);
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}