////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-08 17:50:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3836
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1760KB
//////////////////System Comment End//////////////////
/*«ø¡¨Õ®*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
}E[50000*10];
int head[MAXN],ecnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int In[MAXN],Out[MAXN];
bool Instack[MAXN];
int N,M,top,Index,scc;

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
void Solve()
{
	int i,u,v;
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	memset(In,0,sizeof(In));
	memset(Out,0,sizeof(Out));
	memset(Instack,false,sizeof(Instack));
	Index=top=scc=0;
	for(i=1;i<=N;i++)
	{if(!DFN[i]) Tarjan(i);}
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;
		if(Belong[u]!=Belong[v])
		{
			In[Belong[v]]++;
			Out[Belong[u]]++;
		}
	}
	int in=0,out=0;
	for(i=1;i<=scc;i++)
	{
		if(In[i]==0) in++;
		if(Out[i]==0) out++;
	}
	if(scc==1) 
		printf("0\n");
	else
	printf("%d\n",max(in,out));
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
