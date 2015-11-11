////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-31 20:13:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3986
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:2216KB
//////////////////System Comment End//////////////////
/*±©Á¦É¾±ßÃ¶¾Ù*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define INF 2e9
#define MAXN 2005
//#define min(a,b) (a<b?a:b)
//#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
    bool ok;
}E[2000000];
int head[MAXN],ecnt;
int dis[MAXN],pre[MAXN];
int Q[2000000];
bool vis[MAXN];
int Head,Tail;
int road[MAXN],cnt;
int N,M;

inline int max(int a,int b)
{
return a>b?a:b;
}
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].ok=false;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,j,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<0||u==v) continue;
        Insert(u,v,w);
        Insert(v,u,w);
    }
}
int SPFA()
{
    int i,u,v,w;
    memset(vis,false,sizeof(vis));
    for(i=1;i<=N;i++)
        dis[i]=INF;
    Head=Tail=0;
    Q[Head++]=1;
    vis[1]=true;
    pre[1]=-1;
    dis[1]=0;
    while(Head!=Tail)
    {

        u=Q[Tail++];
        //u=Q.front();Q.pop();
        vis[u]=false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            //printf("*\n");
            if(E[i].ok) continue;
            v=E[i].v;w=E[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    Q[Head++]=v;
                    //Q.push(v);
                }
            }
        }
    }
    return dis[N];
}
void Solve()
{
    int i,u,v,t;

    t=SPFA();
    if(t==INF)
        printf("-1\n");
    else
    {  // printf("*\n");
        cnt=0;
        u=N;
        while(true)
        {
            if(pre[u]==-1) break;
            road[cnt++]=pre[u];
            u=E[pre[u]].u;
        }
        int ans=-1;
        for(i=0;i<cnt;i++)
        {
            E[road[i]].ok=true;
            t=SPFA();
            //ans=min(ans,t);
            ans=max(ans,t);
            E[road[i]].ok=false;
        }
        if(ans==INF) ans=-1;
        printf("%d\n",ans);
    }
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