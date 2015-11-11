////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-08 09:11:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3072
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:4328KB
//////////////////System Comment End//////////////////
/*缩点+dfs*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 50005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
	bool ok;
}E[100005],sE[100005];
int head[MAXN],ecnt;
int shead[MAXN],secnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,scc,top,N,M,scr;
bool Instack[MAXN];
bool vis[MAXN];
int pre[MAXN];//标记指向每个缩点后的点的边号
void Insert(int u,int v,int w,edge E[],int head[],int &ecnt)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].ok=true;
	E[ecnt].next=head[u]; 
	head[u]=ecnt++;
}
void Tarjan(int u)
{
	int i,v;
	Low[u]=DFN[u]=++Index;
	Stack[++top]=u;
	Instack[u]=true;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(!DFN[v])
		{
			Tarjan(v);
			if(Low[u]>Low[v])
				Low[u]=Low[v]; 
		}
		else if(Instack[v]&&Low[u]>DFN[v])
			Low[u]=DFN[v]; 
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do{
			v=Stack[top--];
			Instack[v]=false;
			Belong[v]=scc;
		}while(u!=v);
	}
	return;
}
void Init()
{
	int i,u,v,w;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Insert(u,v,w,E,head,ecnt);
	}
}
void dfs(int u)
{
	int i,v,w;
	for(i=shead[u];i!=-1;i=sE[i].next)
	{
		v=sE[i].v;w=sE[i].w;
		if(!vis[v])
		{
			vis[v]=true;
			pre[v]=i;
			dfs(v); 
		}
		else 
		{
			if(sE[pre[v]].w>w)
			{
				sE[pre[v]].ok=false;
				pre[v]=i;
			}
			else
				sE[i].ok=false;
		}
	}
}
void Solve()
{
	int i,u,v,w;
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(Low,0,sizeof(Low));
	Index=scc=top=0;
	for(i=0;i<N;i++)//缩点
	{if(!DFN[i]) Tarjan(i);}
	//重新建图
	memset(shead,-1,sizeof(shead));secnt=0;
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;w=E[i].w;
		if(Belong[u]!=Belong[v])
			Insert(Belong[u],Belong[v],w,sE,shead,secnt);
	}
	scr=Belong[0];
	memset(pre,-1,sizeof(pre));
	memset(vis,false,sizeof(vis));
	vis[scr]=true;
	dfs(scr);
	__int64 ans=0;
	for(i=0;i<secnt;i++)
	{
		//printf("#%d %d %d %d\n",sE[i].u,sE[i].v,sE[i].w,sE[i].ok);
		if(sE[i].ok) 
			ans+=(double)sE[i].w; 
	}
	printf("%I64d\n",ans);
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}
/*
4 5
0 1 70
0 2 100
2 1 80
2 3 200
3 1 50
*/