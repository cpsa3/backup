////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-08 15:06:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2242
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <stack>
#include <cmath>
#include <algorithm>
#define MAXN 10005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next,id;
}E[40005],sE[40005];
int head[MAXN],ecnt;
int shead[MAXN],secnt;
int low[MAXN],dfn[MAXN],col[MAXN];
int N,M,scc,ans,sum;
int fa[MAXN],Belong[MAXN];
int num[MAXN],W[MAXN];
bool vis[40005],mark;
stack<int>_ST;
void Insert(int u,int v,int id)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].id=id;
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
void swap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t;
}
bool Judge(int u,int v,int id)//(判重)关键这里耗时
{
	int i;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		if(E[i].v==v)
		{vis[E[i].id]=vis[id]=true;return false;} 
	}
	return true;
}
void Run(int v)
{
	int i,x,y;
	scc++;
	while(!_ST.empty())
	{
		x=_ST.top();
		_ST.pop();
		Belong[x]=scc;
		W[scc]+=num[x];
		if(x==v) break;
	}
}
void dfs(int u,int depth)
{
	int i,v;
	_ST.push(u);
	low[u]=dfn[u]=depth;
	col[u]=1;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(v!=fa[u]&&col[v]==1)
			low[u]=min(low[u],dfn[v]);
		if(col[v]==0)
		{
			fa[v]=u;
			dfs(v,depth+1);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v]&&!vis[E[i].id])
				{Run(v);mark=true;}
		}
	}
}
void Init()
{
	int i,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(vis,false,sizeof(vis));
	sum=0;mark=false;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&u,&v);
		u++;v++;
		swap(u,v);
		if(Judge(u,v,i))
		{
			Insert(u,v,i);
			Insert(v,u,i); 
		}
	}
}
int dfs1(int u)
{
	int i,v,res=W[u];
	for(i=shead[u];i!=-1;i=sE[i].next)
	{
		v=sE[i].v;
		if(!vis[v])
		{
			vis[v]=true;
			res+=dfs1(v);
		}
	}
	ans=min(ans,abs(sum-2*res));
	return res;	
}
void Solve()
{
	int i,u,v,w;
	memset(dfn,0,sizeof(dfn));
	memset(col,0,sizeof(col));
	memset(W,0,sizeof(W));
	while(!_ST.empty()) _ST.pop();
	//缩点
	fa[1]=1;
	scc=0;
	dfs(1,0);
	scc++;
	while(!_ST.empty())
	{
		u=_ST.top();_ST.pop();
		Belong[u]=scc;
		W[scc]+=num[u];
	}
	if(!mark)
	{printf("impossible\n");return;}
	//重新建图
	memset(shead,-1,sizeof(shead));secnt=0;
	for(i=0;i<ecnt;i+=2)
	{
		u=E[i].u;
		v=E[i].v;
		if(Belong[u]!=Belong[v])
		{
			sInsert(Belong[u],Belong[v]);
			sInsert(Belong[v],Belong[u]);
		}
	}
	//dfs找最平均的分
	ans=INF;
	memset(vis,false,sizeof(vis));
	vis[1]=true;
	dfs1(1);
	printf("%d\n",ans);
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