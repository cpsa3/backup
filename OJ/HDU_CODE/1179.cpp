////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-01 19:31:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1179
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*最大流*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 205
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[200000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn;
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
	int i,j,w,num,u;
	memset(head,-1,sizeof(head));ecnt=0;
	scr=0;sink=N+M+1;vn=sink+1;
	for(i=1;i<=M;i++)
	{
		scanf("%d",&num);
		Insert(i+N,sink,1);
		for(j=1;j<=num;j++)
		{
			scanf("%d",&u);
			Insert(u,i+N,1);
		}
	}
	for(i=1;i<=N;i++)
		Insert(scr,i,1);
}
int Sap(int s,int t,int n)//核心代码(模版)
{
    int ans=0,aug=INF;//aug表示增广路的流量
    int i,v,u=pre[s]=s;
    for(i=0;i<n;i++)
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
	printf("%d\n",Sap(scr,sink,vn));
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