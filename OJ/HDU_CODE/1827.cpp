////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-02 22:31:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1827
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*强连通缩点*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[200000];
int head[MAXN],ecnt;
int N,M,W[MAXN];
int DFN[MAXN],Low[MAXN],Belong[MAXN],Stack[MAXN];
bool Instack[MAXN];
int H[MAXN];//每个强连通分量里的最小费用
int deg[MAXN];//统计每个连通分量的入度
int top,Index,scc;
void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++; 
}
void Init()
{
	int i,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=N;i++)
		scanf("%d",&W[i]);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&u,&v);
		Insert(u,v);
	}
}
void Tarjan(int u)
{
	int i,v;
	DFN[u]=Low[u]=++Index;
	Stack[++top]=u;
	Instack[u]=true;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(!DFN[v])
		{
			Tarjan(v);
			Low[u]=min(Low[u],Low[v]); 
		}
		else if(Instack[v])
			Low[u]=min(Low[u],DFN[v]);
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do{
			v=Stack[top--];
			Instack[v]=false;
			Belong[v]=scc;
			H[scc]=min(H[scc],W[v]);
		}while(u!=v);
	} 
	return ;
}
void Solve()
{
	int i,u,v;
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	memset(Instack,false,sizeof(Instack));
	memset(deg,0,sizeof(deg));
	for(i=1;i<=N;i++)
		H[i]=INF;
	top=Index=scc=0;
	for(i=1;i<=N;i++)
	{if(!DFN[i]) Tarjan(i);}
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;
		if(Belong[u]!=Belong[v])
			deg[Belong[v]]++;
	}
	int ans=0,cnt=0;
	for(i=1;i<=scc;i++)
	{
		if(!deg[i])
		{
			cnt++;
			ans+=H[i];
		}
	}
	printf("%d %d\n",cnt,ans); 
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