////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-11 16:14:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4067
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:344KB
//////////////////System Comment End//////////////////
/*HDU_4067 Random Maze*/
/*最小费用最大流(巧妙构图)*/
/*
题意：给出n个点，m条边，入口s和出口t，对于每条边有两个值a，b，如果保留这条边需要a花费；否则，移除这条边需要花费b。
      题目要求用最小费用构造一个有向图满足以下条件：
      1.只有一个入口和出口
      2.所有路都是唯一方向
      3.对于入口s，它的出度 = 它的入度 + 1
      4.对于出口t，它的入度 = 它的出度 + 1
      5.除了s和t外，其他点的入度 = 其出度
      最后如果可以构造，输出最小费用；否则输出impossib。         

构图：
(1):建立两个数组in[],out[],分别表示当前构建的图中每个点的入度和出度；
(2):将in[]和out[]初始全为0,ans=0；
(3):对于每条边u->v. 
		if(a<=b)  	//则保留当前边
		{
			Insert(v,u,1,b-a);
			ans+=a;
			in[v]++;out[u]++; 
		} 
		else 		//删除当前边 
		{
			Insert(u,v,1,a-b);
			ans+=b;	
		}
(4):为了满足s和t的出入度，我们虚拟的加上一条t->s的边： in[s]++;out[t]++;
(5):添加源汇点scr和sink
(6):遍历所有点i：
		if(in[i]>=out[i])	
			Insert(scr,i,in[i]-out[i],0);
		else 
			Insert(i,sink,out[i]-in[i],0);
(7):最后跑一遍最小费用最大流 
		if(所有scr的出边都满流)
			ans+=MinCost;
		else
			Impossible;
			
ps.这里说下算法是如何进行调整的：
	举个简单的例子，假如某一个点i,in[i] > out[i],说明当前的入度大于当前的出度，
	那么我们可以这样调整：把之前删除的以i为起点的边添加回来 或者 把之前保留的
	以i为终点的边删除，现在边的费用其实是改变边状态所需要额外付的费用，而最小
	费用流算法就可以帮我选择最小的调整费用，也就是那个mincost。 
*/ 

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 205
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct edge
{
	int u,v,w,c,next;
}E[80000];
int head[MAXN],ecnt;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int in[MAXN],out[MAXN];
int N,M,cas;
int scr,sink,vn,ans,ss,tt,In;

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
	int i,j,u,v,w,c,a,b;
	scanf("%d%d%d%d",&N,&M,&ss,&tt);
	
	scr=0;sink=N+1;vn=sink+1;
	ans=0;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d%d",&u,&v,&a,&b);
		if(a<=b)
		{
			Insert(v,u,1,b-a);
			in[v]++;out[u]++;
			ans+=a;
		}
		else
		{
			Insert(u,v,1,a-b);
			ans+=b;
		}
	}
	
	in[ss]++;out[tt]++;
	
	In=0;
	for(i=1;i<=N;i++)
	{
		if(in[i]>=out[i])
		{
			Insert(scr,i,in[i]-out[i],0);
			In+=in[i]-out[i];
		}
		else	
			Insert(i,sink,out[i]-in[i],0);
	}
}
queue<int>Q;
bool SPFA(int s,int t,int n)
{
	int i,u,v,c;
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
	int flow=0,MinCost=0,i;
	while(SPFA(scr,sink,vn))
	{
		MinCost+=dis[sink];
		flow++;
		for(i=pre[sink];i!=-1;i=pre[E[i].u])
		{
			E[i].w--;
			E[i^1].w++;
		}
	}
	printf("Case %d: ",cas++);
	if(flow==In)
		printf("%d\n",ans+MinCost);
	else 
		printf("impossible\n");
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