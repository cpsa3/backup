////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-09 17:27:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3861
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1704KB
//////////////////System Comment End//////////////////
/*强连通+最小路径覆盖*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 5005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
}E[400000],sE[400000];
int head[MAXN],ecnt;
int shead[MAXN],secnt;
int DFN[MAXN],Low[MAXN],Stack[MAXN],Belong[MAXN];
bool Instack[MAXN],flag[MAXN];
int result[MAXN];
int N,M,Index,top,scc;
void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void sInsert(int u,int v)
{
	sE[secnt].u=u;
	sE[secnt].v=v;
	sE[secnt].next=shead[u];
	shead[u]=secnt++;
}
void Init()
{
	int i,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	scanf("%d%d",&N,&M);
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
	if(DFN[u]==Low[u])
	{
		++scc;
		do{
			v=Stack[top--];
			Instack[v]=false;
			Belong[v]=scc;
		}while(u!=v);
	}
	return;
}
bool Find(int x)
{
	int i,v;
	for(i=shead[x];i!=-1;i=sE[i].next)
	{
		v=sE[i].v;
		if(!flag[v])
		{
			flag[v]=true;
			if(result[v]==-1||Find(result[v]))
			{
				result[v]=x;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{
	int i,ans=0;
	memset(result,-1,sizeof(result));
	for(i=1;i<=scc;i++)
	{
		memset(flag,false,sizeof(flag));
		ans+=Find(i);
	}
	return ans;
}
void Solve()
{
	int i,u,v;
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	Index=top=scc=0;
	for(i=1;i<=N;i++)
	{if(!DFN[i]) Tarjan(i);}

	memset(shead,-1,sizeof(shead));secnt=0;
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;
		if(Belong[u]!=Belong[v])
			sInsert(Belong[u],Belong[v]);
	}
	//最小路径覆盖
	int res=MaxMatch();
	printf("%d\n",scc-res);
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