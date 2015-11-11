////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-29 01:00:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1533
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:672KB
//////////////////System Comment End//////////////////
/*最小费用最大流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXN 250
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,c,w,next; 
}E[200000];
struct Node
{
	int x,y; 
}Man[105],Home[105];
int num_Man,num_Home;
int head[MAXN],ecnt;
int pre[MAXN],dis[MAXN];
bool vis[MAXN],ok;
char map[105][105];
int N,M,scr,sink,vn;
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
	int i,j,c1,c2;
	memset(head,-1,sizeof(head));ecnt=0;
	//ok=false;
	num_Man=num_Home=0;
	for(i=0;i<N;i++)
		scanf("%s",map[i]);
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(map[i][j]=='m')
			{
				Man[num_Man].x=i;
				Man[num_Man++].y=j;
			}
			if(map[i][j]=='H')
			{
				Home[num_Home].x=i;
				Home[num_Home++].y=j; 
			} 
		}
	}
	scr=0;sink=2*num_Man+1;vn=sink+1;
	for(i=1;i<=num_Man;i++)
	{
		Insert(scr,i,1,0);
		Insert(i+num_Man,sink,1,0); 
	}
	for(i=1;i<=num_Man;i++)
	{
		for(j=1;j<=num_Man;j++)
		{
			//Insert(i,j+num_Man,INF,0);
			c1=abs(Man[i-1].x-Home[j-1].x);
			c2=abs(Man[i-1].y-Home[j-1].y);
			Insert(i,j+num_Man,1,c1+c2); 
		}
	}
	/*
	for(i=0;i<ecnt;i++)
	{
		printf("*%d %d %d %d\n",E[i].u,E[i].v,E[i].w,E[i].c);
	}
	*/
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
	int i,ans=0,flow=0;
	while(SPFA(scr,sink,vn))
	{
		//printf("*\n");
		ans+=dis[sink];
		for(i=pre[sink];i!=-1;i=pre[E[i].u])//更新
		{
			E[i].w-=1;
			E[i^1].w+=1;
			//ans+=E[i].c*flow;
		}
	}
	printf("%d\n",ans);
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