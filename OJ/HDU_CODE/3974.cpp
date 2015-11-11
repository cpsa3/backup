////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-26 20:16:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3974
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:5892KB
//////////////////System Comment End//////////////////
/*DFS±êºÅ+Ïß¶ÎÊ÷*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 200010
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
    int s,e,v;
    bool mark;
}Tnode[4*MAXN];
struct edge
{
    int u,v,next;
}E[2000000];
int head[MAXN],ecnt;
int N,cas,root,Index,M;
bool vis[MAXN];
int S1[MAXN],E1[MAXN];
void Insert(int u,int v)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].v=-1;Tnode[p].mark=false;
    if(s==e) return;
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
}
void Update(int p,int s,int e,int V)
{
    if(Tnode[p].mark)
    {
        Tnode[lch(p)].v=Tnode[rch(p)].v=Tnode[p].v;
        Tnode[p].mark=false;
        Tnode[lch(p)].mark=Tnode[rch(p)].mark=true;
    }
    if(Tnode[p].s==s&&Tnode[p].e==e)
    {
        Tnode[p].v=V;
        Tnode[p].mark=true;
        return;
    }


    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(e<=mid)
        Update(lch(p),s,e,V);
    else if(s>mid)
        Update(rch(p),s,e,V);
    else
    {
        Update(lch(p),s,mid,V);
        Update(rch(p),mid+1,e,V);
    }
}
int Query(int p,int k)
{
    if(Tnode[p].mark)
    {
        Tnode[lch(p)].v=Tnode[rch(p)].v=Tnode[p].v;
        Tnode[p].mark=false;
        Tnode[lch(p)].mark=Tnode[rch(p)].mark=true;
    }
    if(Tnode[p].s==Tnode[p].e)
        return Tnode[p].v;

    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k<=mid)
        return Query(lch(p),k);
    else
        return Query(rch(p),k);
}
void Init()
{
    int i,u,v;
    scanf("%d",&N);
    memset(head,-1,sizeof(head));ecnt=0;
    memset(vis,false,sizeof(vis));
    for(i=1;i<=N-1;i++)
    {
        scanf("%d%d",&u,&v);
        Insert(v,u);
        vis[u]=true;
    }
    for(i=1;i<=N;i++)
    {
        if(vis[i]==false)
        {root=i;break;}
    }
    scanf("%d",&M);
}
void dfs(int u)
{
    int i,v;
    S1[u]=++Index;
    for(i=head[u];i!=-1;i=E[i].next)
    {
        v=E[i].v;
        dfs(v);
    }
    E1[u]=++Index;
}
void Print()
{
    int i;
    printf("--------------\n");
    for(i=1;i<=N;i++)
        printf("%d %d \n",S1[i],E1[i]);
    printf("--------------\n");
    for(i=0;i<ecnt;i++)
        printf("%d %d \n",E[i].u,E[i].v);
    printf("******\n");
    printf("%d\n",root);
}
void Solve()
{
    int i,u,k;
    char s[5];
    Index=0;
    dfs(root);
    Build(1,1,2*N+5);
    //Print();
    printf("Case #%d:\n",cas++);
    while(M--)
    {
        scanf("%s",s);
        if(s[0]=='C')
        {
            scanf("%d",&u);
            int ans=Query(1,S1[u]);
            printf("%d\n",ans);
        }
        else
        {
            scanf("%d%d",&u,&k);
            //printf("%d %d\n",S1[u],E1[u]);
            Update(1,S1[u],E1[u],k);
        }
    }
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