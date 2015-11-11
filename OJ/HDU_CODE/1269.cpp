////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-07 20:46:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1269
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1768KB
//////////////////System Comment End//////////////////
/*判断原图是否强连通*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 10005
using namespace std;
struct edge
{
	int u,v,next;
}E[200008];
int head[MAXN],ecnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,scc,top,N,M;
bool Instack[MAXN];
void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
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
	int i,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&u,&v);
		Insert(u,v);
	}
}
void Solve()
{
	int i;
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(Low,0,sizeof(Low));
	Index=scc=top=0;
	for(i=1;i<=N;i++)//缩点
	{
		if(!DFN[i]) 
			Tarjan(i);
		if(scc>1) break;
	}
	if(scc>1) printf("No\n");
	else printf("Yes\n");
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0) break;
		Init();
		Solve();
	}
return 0;
}