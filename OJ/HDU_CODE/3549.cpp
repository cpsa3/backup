////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-27 16:14:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3549
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*最大流模板题*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
    int v,w,next;
}E[4005];
int head[MAXN],ecnt;
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int N,M,scr,sink,vn,cas;
void Insert(int u,int v,int w)
{
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Init()
{
    int i,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    scanf("%d%d",&N,&M);
    scr=1;sink=N;vn=N;
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
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
    printf("Case %d: %d\n",cas++,Sap(scr,sink,vn));
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
