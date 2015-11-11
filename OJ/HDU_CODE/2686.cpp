////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-27 16:15:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2686
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:444KB
//////////////////System Comment End//////////////////
/*最小费用流+拆点*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 5005
#define INF 1e8
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
int N,M,scr,sink,vn;
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
    int i,j,u,v,c,id;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=2*N*N+1;vn=sink+1;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            scanf("%d",&c);
            id=(i-1)*N+j;
            Insert(id,id+N*N,1,c);
            Insert(id,id+N*N,INF,0);
            if(j<N)
                Insert(id+N*N,id+1,INF,0);
            if(i<N)
                Insert(id+N*N,id+N,INF,0);
        }
    }
    Insert(scr,1,2,0);
    Insert(2*N*N,sink,2,0);
}
queue<int>Q;
bool SPFA(int s,int t,int n)
{
    int i,u,v,c;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    for(i=0;i<=n;i++)//找最长路
        dis[i]=-INF;
    Q.push(s);
    pre[s]=-1;
    dis[s]=0;
    vis[s]=true;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        vis[u]=false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;c=E[i].c;
            if(E[i].w>0&&dis[v]<dis[u]+c)
            {
                dis[v]=dis[u]+c;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    if(dis[t]!=-INF) return true;
    return false;
}
void Solve()
{
    int i,ans=0,flow;
    while(SPFA(scr,sink,vn))
    {
        flow=INF;
        ans+=dis[sink];
        for(i=pre[sink];i!=-1;i=pre[E[i].u])//可增进的流量
            flow=min(flow,E[i].w);
        for(i=pre[sink];i!=-1;i=pre[E[i].u])//更新
        {
            E[i].w-=flow;
            E[i^1].w+=flow;
            //ans+=E[i].c*flow;
        }
    }
    printf("%d\n",ans);
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