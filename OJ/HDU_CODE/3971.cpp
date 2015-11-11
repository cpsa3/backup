////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-26 23:05:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3971
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:11496KB
//////////////////System Comment End//////////////////
/*线段树*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 300000
#define Lim 4000
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
    int s,e;
    int Max,Min;
    int v;
}Tnode[4*MAXN];
int W[MAXN];
int N,M;
void fuck(int p)
{
    Tnode[p].Max=max(Tnode[lch(p)].Max,Tnode[rch(p)].Max);
    Tnode[p].Min=min(Tnode[lch(p)].Min,Tnode[rch(p)].Min);
    return;
}
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].v=0;
    if(s==e)
    {
        Tnode[p].Max=Tnode[p].Min=W[s];
        return;
    }
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
    fuck(p);
}
void Go(int p)
{
    if(Tnode[p].v)
    {
        int v=Tnode[p].v;
        Tnode[lch(p)].v+=v;
        Tnode[rch(p)].v+=v;
        Tnode[lch(p)].Max+=v;
        Tnode[lch(p)].Min+=v;
        Tnode[rch(p)].Max+=v;
        Tnode[rch(p)].Min+=v;
        Tnode[p].v=0;
    }
}
void Run(int p)
{
    if(Tnode[p].s==Tnode[p].e)
    {
        W[Tnode[p].s]=Tnode[p].Max;
        return;
    }
    Go(p);//往下传递
    Run(lch(p));
    Run(rch(p));
}
void Update(int p,int s,int e,int d)
{
    if(Tnode[p].Min>e) return;
    if(Tnode[p].Max<s) return;

    if(Tnode[p].Max<=e&&Tnode[p].Min>=s)
    {
        Tnode[p].v+=d;
        Tnode[p].Max+=d;
        Tnode[p].Min+=d;
        return;
    }

    if(Tnode[p].s==Tnode[p].e) return ;
    Go(p);
    Update(lch(p),s,e,d);
    Update(rch(p),s,e,d);
    fuck(p);
}
int Query(int p,int s,int e)
{
    if(Tnode[p].Min>e) return 0;
    if(Tnode[p].Max<s) return 0;

    if(Tnode[p].Max<=e&&Tnode[p].Min>=s)
    {
        return Tnode[p].e-Tnode[p].s+1;
    }

    if(Tnode[p].s==Tnode[p].e) return 0;
    Go(p);
    int res=Query(lch(p),s,e)+Query(rch(p),s,e);
    fuck(p);
    return res;
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d",&W[i]);
}
void Solve()
{
    int i,s,e,d;
    char ss[3];
    sort(W+1,W+N+1);
    Build(1,1,N);
    while(M--)
    {
        if(M%Lim==0)//定期清理线段树
        {
            Run(1);
            sort(W+1,W+N+1);
            Build(1,1,N);
        }
        scanf("%s",ss);
        if(ss[0]=='C')
        {
            scanf("%d%d%d",&s,&e,&d);
            Update(1,s,e,d);
        }
        else
        {
            scanf("%d%d",&s,&e);
            int ans=Query(1,s,e);
            printf("%d\n",ans);
        }
    }
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




