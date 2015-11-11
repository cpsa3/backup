////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-14 11:44:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3666
////Problem Title: 
////Run result: Accept
////Run time:843MS
////Run memory:7776KB
//////////////////System Comment End//////////////////
/*HDU_3666 THE MATRIX PROBLEM*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define MAXN 805
#define INF (1e10)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,next;
    double w;
}E[800000];
int head[MAXN],ecnt;
int N,M;
int Q[200000];
int Head,Tail;
bool vis[MAXN];
double L,R,ll,rr;
double dis[MAXN];
//dv<=du+w;
void Insert(int u,int v,double w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,j;
    double a,w;
    ll=log(L*1.0);
    rr=log(R*1.0);
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%lf",&a);
            w=log(a*1.0);
            Insert(j+N,i,rr-w);
            Insert(i,j+N,w-ll);
        }
    }
}
bool SPFA()
{
    int i,u,v,sum=0;
    double w;
    memset(vis,false,sizeof(vis));
    Head=Tail=0;
    for(i=1;i<=N+M;i++)
        dis[i]=INF;
    dis[1]=0;
    vis[1]=true;
    Q[Head++]=1;
    sum++;
    while(Head!=Tail)
    {
        u=Q[Tail++];
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
                    sum++;
                    if(sum>2*(N+M)) return false;
                    Q[Head++]=v;
                }
            }
        }
    }
    return true;
}
void Solve()
{
    bool ans=SPFA();
    if(ans) printf("YES\n");
    else printf("NO\n");
}
int main()
{
    while(scanf("%d%d%lf%lf",&N,&M,&L,&R)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}