////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 23:39:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3947
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:340KB
//////////////////System Comment End//////////////////
/*不等式建图，最小费用最大流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>
#define MAXN 200
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,c,next; 
}E[200000];
int head[MAXN],ecnt;
int dis[MAXN],pre[MAXN];
bool vis[MAXN];
int N,M,cas,scr,sink,vn;
int W[MAXN],fa[MAXN],Son[MAXN],Sum;
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
	memset(Son,0,sizeof(Son));
	scanf("%d",&N);
	scr=0;sink=N+1;vn=sink+1;Sum=0;
	for(i=1;i<N;i++)
	{
		scanf("%d%d",&u,&v);
		fa[u]=v;
		scanf("%d",&W[u]); 
	}
	W[1]=0;//另外添加
	scanf("%d",&M);
	for(i=1;i<=M;i++)//(1) 
	{
		scanf("%d%d%d%d",&u,&v,&w,&c);
		Insert(u,v,w,c);  
	}
	for(i=2;i<=N;i++)//(2)每父节点向他们的子节点连一条<INF,0>
		Insert(fa[i],i,INF,0);
	for(i=2;i<=N;i++)
		Son[fa[i]]+=W[i];
	for(i=1;i<=N;i++)//(3):连接源汇点
	{
		w=W[i]-Son[i];
		if(w>0)
		{
			Insert(scr,i,w,0);
			Sum+=w;//???
		}
		else if(w<0)
		{
			Insert(i,sink,-w,0);
			//Sum+=W[i];//??
		}
	}
}
void Print()
{
	int i;
	for(i=0;i<ecnt;i+=2)
		printf("%d %d %d %d\n",E[i].u,E[i].v,E[i].w,E[i].c);
	printf("--------------------\n");

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
	//Print();
	while(SPFA(scr,sink,vn))
	{
		
		flow=INF;
		for(i=pre[sink];i!=-1;i=pre[E[i].u])
			flow=min(flow,E[i].w);
		for(i=pre[sink];i!=-1;i=pre[E[i].u])
		{
			E[i].w-=flow;
			E[i^1].w+=flow; 
		} 
		//printf("*%d %d\n",flow,dis[sink]);
		Max_flow+=flow;
		ans+=dis[sink]*flow; 
	} 
	if(Max_flow<Sum) ans=-1;
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