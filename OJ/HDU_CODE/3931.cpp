////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 12:36:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3931
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:372KB
//////////////////System Comment End//////////////////
/*最小割+拆点*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 600
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
	int x,y,r,p;
}node[MAXN];
struct edge
{
	int u,v,w,next;
}E[20000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int L,W,N,P,scr,sink,vn;
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
bool Judge(int a,int b)
{
	double dx=(node[a].x-node[b].x);
	double dy=(node[a].y-node[b].y);
	double l=sqrt((double)(dx*dx+dy*dy));
	return (double)(node[a].r+node[b].r)>=l;
}
void Init()
{
	int i,j;
	memset(head,-1,sizeof(head));ecnt=0;
	scr=0;sink=2*N+1;vn=sink+1;
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d%d",&node[i].x,&node[i].y,&node[i].r,&node[i].p);
		Insert(i,i+N,node[i].p);
		if(node[i].r>=node[i].y)
			Insert(scr,i,INF);
		if(node[i].y+node[i].r>=W)
			Insert(i+N,sink,INF);
	}
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			if(Judge(i,j))
			{
				Insert(i+N,j,INF);
				Insert(j+N,i,INF);
			}
		}
	}
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
void Solve()
{
	int Min_flow=Sap(scr,sink,vn);
	int ans=P-Min_flow;
	if(ans<=0)
		printf("Our hero has been killed\n");
	else
		printf("%d\n",ans);
}
int main()
{
	while(scanf("%d%d%d%d",&L,&W,&N,&P)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}
