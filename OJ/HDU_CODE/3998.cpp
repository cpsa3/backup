////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-02 18:23:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3998
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1876KB
//////////////////System Comment End//////////////////
/*DP+网络流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 200006
#define INF 2e9
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int N,scr,sink,vn,LEN;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int W[MAXN],dp[MAXN];
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
void DP()
{
    int i,j,t;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=N;i++)
    {
        t=0;
        for(j=1;j<i;j++)
        {
            if(W[i]>W[j])
                t=max(t,dp[j]);
        }
        dp[i]=t+1;
    }
    LEN=0;
    for(i=1;i<=N;i++)
        LEN=max(LEN,dp[i]);
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d",&W[i]);
    DP();
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
    int i,j;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=2*N+1;vn=sink+1;
    for(i=1;i<=N;i++)
    {
        Insert(i,i+N,1);
        if(dp[i]==1)
            Insert(scr,i,1);
        if(dp[i]==LEN)
            Insert(i+N,sink,1);
    }
    for(i=1;i<=N;i++)
    {
        for(j=i+1;j<=N;j++)
        {
            if(W[j]>W[i]&&dp[i]+1==dp[j])
                Insert(i+N,j,1);
        }
    }
    int ans=Sap(scr,sink,vn);
    printf("%d\n%d\n",LEN,ans);
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}		
