////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-17 11:00:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3061
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:2032KB
//////////////////System Comment End//////////////////
/*HDU_3061 Battle*/
/*最大权闭合图*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 505
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[200000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn,Sum;
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
void Init()
{
    int i,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=N+1;vn=sink+1;Sum=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&w);
        if(w>0)
        {
            Sum+=w;
            Insert(scr,i,w);
        }
        else
            Insert(i,sink,-w);
    }
    for(i=1;i<=M;i++)
    {
        scanf("%d%d",&u,&v);
        Insert(u,v,INF);
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
    int ans=Sap(scr,sink,vn);
    ans=Sum-ans;
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
