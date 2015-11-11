////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-10 22:51:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3887
////Problem Title: 
////Run result: Accept
////Run time:859MS
////Run memory:10608KB
//////////////////System Comment End//////////////////
/*DFS+Ïß¶ÎÊ÷O(N*logN)*/
/*AC´úÂë£º968ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 200000
#define INF 1e8
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
}E[MAXN];
int head[MAXN],ecnt;

struct Tree
{
	int s,e,num;
}Tnode[2*MAXN];

int S1[MAXN],E1[MAXN];
int f[MAXN],cur[MAXN];
int Stack[10000000];
bool vis[MAXN];
int N,P,top,cnt,num;

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
	for(i=1;i<N;i++)
	{
		scanf("%d%d",&u,&v);
		Insert(u,v);
		Insert(v,u);
	}
}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;Tnode[p].num=0;
	if(s==e) return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Update(int p,int k)
{
	Tnode[p].num++;
	if(Tnode[p].s==Tnode[p].e)
		return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(k<=mid)
		Update(lch(p),k);
	else 
		Update(rch(p),k);
}
int Query(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].num;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		return Query(lch(p),s,e);
	else if(s>mid)
		return Query(rch(p),s,e);
	else
		return Query(lch(p),s,mid)+Query(rch(p),mid+1,e);
}

void dfs()
{
	int i,u,v;
	memset(vis,false,sizeof(vis));
	for(i=1;i<=N;i++)
		cur[i]=head[i];
	top=num=0;
	Stack[++top]=P;
	while(top)
	{
		//printf("*\n");
		u=Stack[top];
		if(!vis[u])
		{
			S1[u]=++num;
			vis[u]=true;
		}
		for(;cur[u]!=-1;cur[u]=E[cur[u]].next)
		{
			v=E[cur[u]].v;
			if(vis[v]) continue;
			Stack[++top]=v;
			break;
		}
		//printf("*%d %d\n",Stack[top],u);
		if(Stack[top]==u)
		{
			E1[u]=++num;
			top--;
		}
	}
}

void Solve()
{
	int u,v,i;
	dfs();
	memset(f,0,sizeof(f));
	Build(1,1,2*N);
	for(i=1;i<=N;i++)
	{
		f[i]=Query(1,S1[i],E1[i]);
		//f[i]/=2;
		Update(1,S1[i]);
		//Update(1,E1[i]);
	}
	for(i=1;i<N;i++)
		printf("%d ",f[i]);
	printf("%d\n",f[i]);
}
int main()
{
	while(scanf("%d%d",&N,&P)!=EOF)
	{
		if(N==0&&P==0) break;
		Init();
		Solve();
	}
	return 0;
}