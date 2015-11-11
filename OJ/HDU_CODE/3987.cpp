////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-31 18:40:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3987
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:11668KB
//////////////////System Comment End//////////////////
/*费用流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 2005
#define MAXM 200007
#define INF (((__int64)1)<<50)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
    int u,v,next;
    __int64 w;
}E[3000000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],pre[MAXN],dis[MAXN];
int N,M,scr,sink,vn,cas,CNT;
int U[MAXM],V[MAXM],KIND[MAXM];
__int64 W[MAXM];
void Insert(int u,int v,__int64 w)
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
    int i,j;
    __int64 w;
    memset(head,-1,sizeof(head));ecnt=0;
    scanf("%d%d",&N,&M);
    CNT=M;
    scr=0;sink=N-1;vn=sink+1;
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%I64d%d",&U[i],&V[i],&W[i],&KIND[i]);
        CNT+=KIND[i];
    }
    for(i=1;i<=M;i++)
    {
        Insert(U[i],V[i],(__int64)(W[i]*(1001)+1));
        if(KIND[i])
            Insert(V[i],U[i],(__int64)(W[i]*(1001)+1));
    }
}
__int64 Sap(int s,int t,int n)//核心代码(模版)
{
    __int64 ans=0,aug=INF;//aug表示增广路的流量
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
    int i;
    __int64 ans=Sap(scr,sink,vn);
    ans=ans%(1001);
    printf("Case %d: %I64d\n",cas++,ans);
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