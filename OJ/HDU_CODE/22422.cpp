////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:18:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2242
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1564KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAXN 10005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct edge
{
    int u,v,next,id;
}E[40005],sE[40005];
int head[MAXN],ecnt;
int shead[MAXN],secnt;

int Low[MAXN],DFN[MAXN],col[MAXN];
bool vis[40005];
int N,M,scc,Top,Sum,ans;
int ST[MAXN],Belong[MAXN];
int num[MAXN],W[MAXN],fa[MAXN];
bool ok;

void Insert(int u,int v,int id)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].id=id;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void sInsert(int u,int v)
{
    sE[secnt].u=u;
    sE[secnt].v=v;
    sE[secnt].next=shead[u];
    shead[u]=secnt++;
}
void swap(int &u,int &v)
{
    if(u>v)
    {int t=u;u=v;v=t;}
}
bool Judge(int u,int v,int id)
{
    int i;
    for(i=head[u];i!=-1;i=E[i].next)
    {
        if(E[i].v==v)
        {
            vis[E[i].id]=vis[id]=true;
            return false;
        }
    }
    return true;
}
void Init()
{
    int i,u,v;
    memset(head,-1,sizeof(head));ecnt=0;
    memset(vis,false,sizeof(vis));
    Sum=0;
    ok=false;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        Sum+=num[i];
    }
    for(i=1;i<=M;i++)
    {
        scanf("%d%d",&u,&v);
        u++;v++;
        swap(u,v);
        if(Judge(u,v,i))
        {
            Insert(u,v,i);
            Insert(v,u,i);
        }
    }
}
void Run(int u)
{
    int v;
    scc++;
    while(Top)
    {
        v=ST[--Top];
        Belong[v]=scc;
        W[scc]+=num[v];
        if(u==v) break;
    }
}
void dfs(int u,int depth)
{
    int i,v;
    ST[Top++]=u;
    Low[u]=DFN[u]=depth;
    col[u]=1;
    for(i=head[u];i!=-1;i=E[i].next)
    {
        v=E[i].v;
        if(v!=fa[u]&&col[v]==1)
            Low[u]=min(Low[u],DFN[v]);
        if(col[v]==0)
        {
            fa[v]=u;
            dfs(v,depth+1);
            Low[u]=min(Low[u],Low[v]);
            if(DFN[u]<Low[v]&&!vis[E[i].id])
            {
                Run(v);
                ok=true;
            }
        }
    }
    col[u]=2;
}
int dfs1(int u)
{
    int i,v,res=W[u];
    vis[u]=true;
    for(i=shead[u];i!=-1;i=sE[i].next)
    {
        v=sE[i].v;
        if(!vis[v]) res+=dfs1(v);
    }
    ans=min(ans,abs(Sum-2*res));
    return res;
}
void Solve()
{
    int i,u,v;
    memset(Low,0,sizeof(Low));
    memset(DFN,0,sizeof(DFN));
    memset(col,0,sizeof(col));
    memset(fa,-1,sizeof(fa));
    memset(W,0,sizeof(W));
    Top=scc=0;
    fa[1]=1;
    dfs(1,1);
    scc++;
    while(Top)
    {
        v=ST[--Top];
        Belong[v]=scc;
        W[scc]+=num[v];
    }

    if(!ok) {printf("impossible\n");return;}
    //÷ÿ–¬ππÕº
    memset(shead,-1,sizeof(shead));secnt=0;
    for(i=0;i<ecnt;i+=2)
    {
        u=E[i].u;v=E[i].v;
        if(Belong[v]!=Belong[u])
        {
            sInsert(Belong[u],Belong[v]);
            sInsert(Belong[v],Belong[u]);
        }
    }
    memset(vis,false,sizeof(vis));
    ans=INF;
    //vis[1]=true;
    dfs1(1);
    printf("%d\n",ans);
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