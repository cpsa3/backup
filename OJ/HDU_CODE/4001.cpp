////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-04 12:59:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4001
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:8128KB
//////////////////System Comment End//////////////////
/*拓扑排序+强连通缩点+SPFA*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define INF (((__int64)(1))<<50)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int a,b,kind;
    __int64 c;
}node[MAXN];
struct edge
{
    int u,v,next;
    __int64 w;
}E[2000000];
int head[MAXN],ecnt;
int Q[2000000];
bool vis[MAXN];
__int64 dis[MAXN];
int Head,Tail;
int N,scr;
int cmp(const void *p1,const void *p2)
{
    if(((struct Node *)p2)->a!=((struct Node *)p1)->a)
        return  ((struct Node *)p2)->a-((struct Node *)p1)->a;
    else if(((struct Node *)p2)->b!=((struct Node *)p1)->b)
        return ((struct Node *)p2)->b-((struct Node *)p1)->b;
    return ((struct Node *)p1)->kind-((struct Node *)p2)->kind;
}
void Insert(int u,int v,__int64 w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
bool Judge(int u,int v)
{
    int da=node[u].a-node[v].a;
    int db=node[u].b-node[v].b;
    if(node[u].kind==0)
    {
        if(da>=0&&db>=0) return true;
    }
    else if(node[u].kind==1)
    {
        if(da>=0&&db>0||da>0&&db>=0) return true;
    }
    else
    {
        if(da>0&&db>0) return true;
    }
    return false;
}
void Build()
{
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=i+1;j<=N;j++)
        {
            //if(i==j) continue;
            if(Judge(i,j))
               Insert(i,j,node[j].c);
        }
    }
    for(i=1;i<=N;i++)
        Insert(scr,i,node[i].c);
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%I64d%d",&node[i].a,&node[i].b,&node[i].c,&node[i].kind);
        if(node[i].a<node[i].b)
        {
            node[i].a^=node[i].b;
            node[i].b^=node[i].a;
            node[i].a^=node[i].b;
        }
    }
    qsort(node+1,N,sizeof(node[0]),cmp);
    Build();//建图
}
__int64 SPFA(int s)
{
    int i,u,v;
    __int64 w;
    memset(vis,false,sizeof(vis));
    for(i=0;i<=N;i++)
        dis[i]=-1;
    Head=Tail=0;
    dis[s]=0;
    vis[s]=true;
    Q[Head++]=s;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        vis[u]=false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;w=E[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    Q[Head++]=v;
                    vis[v]=true;
                }
            }
        }
    }
    __int64 res=0;
    for(i=1;i<=N;i++)
        res=max(res,dis[i]);
    return res;
}
void Solve()
{
    __int64 ans=SPFA(0);
    printf("%I64d\n",ans);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}
