////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-14 00:32:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3667
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:820KB
//////////////////System Comment End//////////////////
/*最小费用最大流+拆边*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 105
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,c,next;
}E[2000000];
int head[MAXN],ecnt;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int Q[2000000];
int Head,Tail;
int N,M,K,scr,sink,vn;
void Insert(int u,int v,int w,int c)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].c=c;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].c=-c;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Init()
{
    int i,j,u,v,w,c,t;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=N+1;vn=sink+1;
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%d%d",&u,&v,&c,&w);
        t=1;
        while(w--)
        {
            Insert(u,v,1,t*c);
            t+=2;
        }
    }
    Insert(scr,1,K,0);
    Insert(N,sink,K,0);
}
bool SPFA(int s,int t,int n)
{
    int i,u,v,c;
    memset(vis,false,sizeof(vis));
    for(i=0;i<=n;i++)
        dis[i]=INF;
    Head=Tail=0;
    Q[Head++]=s;
    pre[s]=-1;
    dis[s]=0;
    vis[s]=true;
    while(Head!=Tail)
    {
        //printf("^\n");
        u=Q[Tail++];
        vis[u]=false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;c=E[i].c;
            if(E[i].w>0&&dis[v]>dis[u]+c)//?°ìáê?E[i].w>0
            {
                dis[v]=dis[u]+c;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    Q[Head++]=v;
                }
            }
        }
    }
    if(dis[t]<INF) return true; //×￠òa?aà?òa>0
    return false;
}
void Solve()
{
    int i,ans=0,flow,F=0;
    while(SPFA(scr,sink,vn))
    {
        ans+=dis[sink];
        F++;
        for(i=pre[sink];i!=-1;i=pre[E[i].u])//?üD?
        {
            E[i].w--;
            E[i^1].w++;
        }
    }
    if(F!=K) ans=-1;
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d%d",&N,&M,&K)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}