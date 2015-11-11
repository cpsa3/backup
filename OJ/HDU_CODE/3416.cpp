////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-27 19:00:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3416
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:5008KB
//////////////////System Comment End//////////////////
/*双向最短路确定最短路的边+最大流(图边连通度)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 1005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[400005],G1[100005],G2[MAXN];
int head[MAXN],ecnt;
int head1[MAXN],ecnt1;
int head2[MAXN],ecnt2;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
bool vis[MAXN];
int d1[MAXN],d2[MAXN];
int N,M,scr,sink,vn;
void Insert(int u,int v,int w)//网络流构图
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
void Insert1(int u,int v,int w)//正向构图
{
	G1[ecnt1].u=u;
	G1[ecnt1].v=v;
	G1[ecnt1].w=w;
	G1[ecnt1].next=head1[u];
	head1[u]=ecnt1++;
}
void Insert2(int u,int v,int w)//反向构图
{
	G2[ecnt2].u=u;
	G2[ecnt2].v=v;
	G2[ecnt2].w=w;
	G2[ecnt2].next=head2[u];
	head2[u]=ecnt2++;
}
void Init()
{
	int i,u,v,w;
	scanf("%d%d",&N,&M);
	memset(head,-1,sizeof(head));ecnt=0;
	memset(head1,-1,sizeof(head1));ecnt1=0;
	memset(head2,-1,sizeof(head2));ecnt2=0;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Insert1(u,v,w);
		Insert2(v,u,w);
	}
	scanf("%d%d",&scr,&sink);
	vn=N;
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
queue<int>Q;
void SPFA(int s,int n,int d[],edge E[],int head[])
{
	int i,u,v,w;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	vis[s]=true;
	Q.push(s);
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;w=E[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vis[v])
				{
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
}
void Solve()
{
	int i,u,v,w,ans;
	//正反向分别求最短路
	SPFA(scr,N,d1,G1,head1);
	SPFA(sink,N,d2,G2,head2);
	int min_dis=d1[sink];
	for(i=0;i<ecnt1;i++)//遍历所有边，确定在最短路上的边
	{
		u=G1[i].u;v=G1[i].v;w=G1[i].w;
		if(d1[u]+d2[v]+w==min_dis)
			Insert(u,v,1);
	}
	printf("%d\n",Sap(scr,sink,vn));
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