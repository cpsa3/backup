////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 00:51:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3917
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:924KB
//////////////////System Comment End//////////////////
/*最大权闭合图*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 5005
#define INF 1e8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[200000],E1[200000],E2[200000];
int head[MAXN],ecnt;
int head1[MAXN],ecnt1;
int head2[MAXN],ecnt2;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,K,scr,sink,vn,Sum;
int W[MAXN];
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
void Insert1(int u,int v,int w)//正向图
{
	E1[ecnt1].u=u;
	E1[ecnt1].v=v;
	E1[ecnt1].w=w;
	E1[ecnt1].next=head1[u];
	head1[u]=ecnt1++;
}
void Insert2(int u,int v,int w)//反向图
{
	E2[ecnt2].u=u;
	E2[ecnt2].v=v;
	E2[ecnt2].w=w;
	E2[ecnt2].next=head2[u];
	head2[u]=ecnt2++;
}
void Build()
{
	int i,j,k,u,v,w;
	scr=0;sink=M+1;vn=sink+1;
	Sum=0;
	for(i=1;i<=M;i++)
	{
		if(W[i]>0)
		{
			Sum+=W[i];
			Insert(scr,i,W[i]);
		}
		else if(W[i]<0)
			Insert(i,sink,-W[i]);
	}
	for(i=1;i<=N;i++)
	{
		for(j=head1[i];j!=-1;j=E1[j].next)
		{
			u=E1[j].w;
			for(k=head2[i];k!=-1;k=E2[k].next)
			{
				v=E2[k].w;
				if(u!=v)
				{
					Insert(v,u,INF);
				}
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
void Init()
{
	int i,u,v,id,w;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(head1,-1,sizeof(head1));ecnt1=0;
	memset(head2,-1,sizeof(head2));ecnt2=0;
	for(i=1;i<=M;i++)
		scanf("%d",&W[i]);
	scanf("%d",&K);
	for(i=1;i<=K;i++)
	{
		scanf("%d%d%d%d",&u,&v,&id,&w);
		W[id]-=w;
		Insert1(u,v,id);
		Insert2(v,u,id);
	}
	Build();
}
void Solve()
{
	int ans=Sum-Sap(scr,sink,vn);
	if(ans<0) ans=0;
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
	