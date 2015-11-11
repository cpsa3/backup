////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-07-11 14:44:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1384
////Problem Title: 
////Run result: Accept
////Run time:2171MS
////Run memory:2528KB
//////////////////System Comment End//////////////////
/*≤Ó∑÷‘º ¯*/
#include <iostream>
#include <queue>
#define MAXN 50005
#define INF 1e8
using namespace std;
struct edge
{
	int v,w,next; 
}E[3*MAXN];
int head[MAXN],ecnt;
int dis[MAXN];
bool vis[MAXN];
int N,ll,rr;
void Insert(int u,int v,int w)
{
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].next=head[u];
	head[u]=ecnt++; 
}
void Init()
{
	int i,u,v,w;
	memset(head,-1,sizeof(head));ecnt=0;
	ll=INF;rr=-INF;
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(v+1>rr) rr=v+1;
		if(u<ll) ll=u;
		Insert(u,v+1,w);
	}
	for(i=ll;i<rr;i++)
	{
		Insert(i,i+1,0);
		Insert(i+1,i,-1); 
	} 
}
queue<int>Q;
void SPFA()
{
	int i,u,v,w;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=ll;i<=rr;i++)
		dis[i]=-INF;
	dis[ll]=0;
	vis[ll]=true;
	Q.push(ll);
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;w=E[i].w;
			if(dis[v]<dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					Q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	printf("%d\n",dis[rr]); 
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
	Init();
	SPFA();
	}
return 0;
}