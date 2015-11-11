////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-26 16:27:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2767
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:1884KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 20007
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct edge
{
	int u,v,next;
}E[2000000];
int head[MAXN],ecnt;
int Stack[MAXN],Belong[MAXN],Low[MAXN],DFN[MAXN];
bool vis[MAXN];
int In[MAXN],Out[MAXN];
int N,M,scc,top,Index;

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
	Low[u]=DFN[u]=++Index;
	vis[u]=true;
	Stack[++top]=u;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(!DFN[v])
		{
			Tarjan(v);
			Low[u]=min(Low[u],Low[v]);
		}
		else if(vis[v])
			Low[u]=min(Low[u],DFN[v]);
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do{
			v=Stack[top--];
			Belong[v]=scc;
			vis[v]=false;
		}while(u!=v);
	}
	return;
}
void Solve()
{
	int i,u,v;
	memset(vis,false,sizeof(vis));
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	Index=top=scc=0;
	for(i=1;i<=N;i++)
	{
		if(!DFN[i])
			Tarjan(i);
	}
	if(scc==1) {printf("0\n");return;}
	memset(In,0,sizeof(In));
	memset(Out,0,sizeof(Out));
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;
		if(Belong[u]!=Belong[v])
		{
			In[Belong[v]]++;
			Out[Belong[u]]++;
		}
	}
	int s1,s2;
	s1=s2=0;
	for(i=1;i<=scc;i++)
	{
		if(In[i]==0) s1++;
		if(Out[i]==0) s2++;
	}
	printf("%d\n",max(s1,s2));
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