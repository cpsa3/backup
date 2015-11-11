////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-07 21:34:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3639
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:916KB
//////////////////System Comment End//////////////////
/*缩点+反向建图dfs*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 5005
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
}E[30001],sE[30000];
int head[MAXN],ecnt;
int shead[MAXN],secnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,scc,top,N,M,cas;
int num[MAXN],W[MAXN];
bool Instack[MAXN];
bool vis[MAXN];
int In[MAXN];
int ans[MAXN],cnt;//保存最后答案
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
			num[scc]++;
		}while(u!=v);
	}
	return;
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
void dfs(int root,int u)
{
	int i,v,w;
	for(i=shead[u];i!=-1;i=sE[i].next)
	{
		v=sE[i].v;
		if(!vis[v])
		{
			vis[v]=true;
			W[root]+=num[v];
			dfs(root,v);
		}
	}
}
void Solve()
{
	int i,u,v;
	memset(num,0,sizeof(num));
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(Low,0,sizeof(Low));
	Index=scc=top=0;
	for(i=0;i<N;i++)//缩点
	{if(!DFN[i]) Tarjan(i);}
	//重新反向构图
	memset(shead,-1,sizeof(shead));secnt=0;
	memset(In,0,sizeof(In));
	memset(W,0,sizeof(W));
	for(i=0;i<ecnt;i++)
	{
		u=E[i].u;v=E[i].v;
		if(Belong[u]!=Belong[v])
		{
			sInsert(Belong[v],Belong[u]);
			In[Belong[u]]++;
		}
	}
	//printf("***\n");
	for(i=1;i<=scc;i++)
	{
		if(!In[i])
		{
			memset(vis,false,sizeof(vis));
			vis[i]=true;
			W[i]=num[i];
			dfs(i,i);
		}
	}
	int Max=0;
	for(i=1;i<=scc;i++)
		Max=max(Max,W[i]);
	cnt=0;
	for(i=0;i<N;i++)
	{
		u=Belong[i];
		if(W[u]==Max)
			ans[cnt++]=i;
	}
	sort(ans,ans+cnt);
	printf("Case %d: %d\n",cas++,Max-1);
	for(i=0;i<cnt-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[i]);
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