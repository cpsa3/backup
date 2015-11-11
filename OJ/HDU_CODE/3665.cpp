////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-14 10:40:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3665
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*HDU_3665 Seaside*/
/*×î¶ÌÂ·*/
/*AC´úÂë£º0ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 15
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[20000];
int head[MAXN],ecnt;
int N,M,P;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
bool mark[MAXN];
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,j,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    memset(mark,false,sizeof(mark));
    for(i=0;i<N;i++)
    {
        scanf("%d%d",&M,&P);
        if(P) mark[i]=true;
        for(j=1;j<=M;j++)
        {
            scanf("%d%d",&v,&w);
            Insert(i,v,w);
        }
    }
}
queue<int>Q;
void SPFA()
{
    int i,u,v,w;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    for(i=0;i<N;i++)
        dis[i]=INF;
    Q.push(0);
    vis[0]=true;
    dis[0]=0;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        vis[u]=false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;w=E[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
}
void Solve()
{
    SPFA();
    int ans=INF,i;
    for(i=0;i<N;i++)
    {
        if(mark[i]&&dis[i]<ans)
            ans=dis[i];
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