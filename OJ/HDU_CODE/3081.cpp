////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-28 20:14:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3081
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:664KB
//////////////////System Comment End//////////////////
/*并查集+最大流+二分枚举*/
/*
思路：
先用并查集(Floyd)处理女生友情的传递。
每个女向她喜欢的所有男生以及她朋友喜欢的男生连一条容量为1的边。
二分最大能进行的轮数ans，源点向每个女生连一条容量为ans的边，
每个男生向汇点连一条容量为ans的边。判断最大流是否等于ans*N;
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 250
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next; 
}E[200000],G[200005];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],pre[MAXN],dis[MAXN];
int p[MAXN];
bool map[MAXN][MAXN];
int N,M,F,scr,sink,vn;
void Insert(int u,int v,int w)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
	E[ecnt].u=v;
	E[ecnt].v=u;
	E[ecnt].w=0;
	E[ecnt].next=head[v];
	head[v]=ecnt++;
}
int find_set(int x)
{
	if(p[x]!=x)
		p[x]=find_set(p[x]);
	return p[x];
}
void unite_set(int x,int y)
{
	int dx=find_set(x);
	int dy=find_set(y);
	if(dx!=dy)
		p[dx]=dy;
}
void Init()
{
	int i,u,v;
	scanf("%d%d%d",&N,&M,&F);
	for(i=1;i<=N;i++)
		p[i]=i;
	scr=0;sink=2*N+1;vn=sink+1;
	for(i=1;i<=M;i++)
		scanf("%d%d",&G[i].u,&G[i].v);
	for(i=1;i<=F;i++)
	{
		scanf("%d%d",&u,&v);
		unite_set(u,v);
	}
	
	for(i=1;i<=N;i++)
		find_set(i);
		
}
int Sap(int s,int t,int n)//核心代码(模版)
{
    int ans=0,aug=INF;//aug表示增广路的流量
    int i,v,u=pre[s]=s;
    for(i=0;i<=n;i++)
    {
        cur[i]=head[i];
        dis[i]=gap[i]=0;
    }
    gap[s]=n;
    bool flag;
    while(dis[s]<n)
    {
        flag=false;
        for(int &j=cur[u];j!=-1;j=E[j].next)//一定要定义成int &j,why
        {
            v=E[j].v;
            if(E[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=true;//找到容许边
                aug=min(aug,E[j].w);
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    ans+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        E[cur[u]].w-=aug;
                        E[cur[u]^1].w+=aug;//注意
                    }
                    aug=INF;
                }
                break;//找到一条就退出
            }
        }
        if(flag) continue;
        int mindis=n;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(E[i].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return ans;
}
bool Judge(int mid)
{
	int i,j,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(map,false,sizeof(map));
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			u=G[i].u;v=G[i].v;
			if(p[j]==p[u]&&!map[j][v+N])
			{
				Insert(j,v+N,1);
				map[j][v+N]=true;
			}
		}
	}
	for(i=1;i<=N;i++)
	{
		Insert(scr,i,mid);
		Insert(i+N,sink,mid); 
	}
	return Sap(scr,sink,vn)==(N*mid); 
}
void Solve()
{
	int l,r,mid;
	l=0;r=N;
	while(l!=r)
	{
		//printf("*\n");
		mid=(l+r+1)>>1;
		if(Judge(mid)) l=mid;
		else r=mid-1; 
	}
	printf("%d\n",l); 
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