////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-18 20:19:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4027
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:7184KB
//////////////////System Comment End//////////////////
/*HDU_4027 Can you answer these queries?*/
/*线段树*/
/*
思路：
(1):在区间加一个ok标记，表示整个区间是否都变为1;
(2):询问时可能存在s>e的数据
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define type __int64
#define MAXN 100005
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Tree
{
    int s,e;
    type sum;
    bool ok;                  //标记区间[s,e]是否都变为1；
    void go()
    {
        sum=(type)sqrt(1.0*sum);
        if(sum==1) ok=true;
        else ok=false;
    }
}Tnode[4*MAXN];

int N,M,cas;
type W[MAXN];

void fuck(int p)
{

    //if((Tnode[lch(p)].ok)&&(Tnode[rch(p)].ok))
    //    Tnode[p].ok=true;
    Tnode[p].sum=Tnode[lch(p)].sum+Tnode[rch(p)].sum;
    Tnode[p].ok=(Tnode[lch(p)].ok)&(Tnode[rch(p)].ok);
    return;
}
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].ok=false;  //注意
    if(s==e)
    {
        Tnode[p].sum=W[s];
        if(W[s]==1) Tnode[p].ok=true;
        else Tnode[p].ok=false;
        return;
    }
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
    fuck(p);
}
void Update(int p,int s,int e)
{
    if(Tnode[p].ok) return;
    if(Tnode[p].s==Tnode[p].e)
    {
        Tnode[p].go();
        return;
    }
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(e<=mid)
        Update(lch(p),s,e);
    else if(s>mid)
        Update(rch(p),s,e);
    else
    {
        Update(lch(p),s,mid);
        Update(rch(p),mid+1,e);
    }
    fuck(p);
}
type Query(int p,int s,int e)
{
    if(Tnode[p].s==s&&Tnode[p].e==e)
        return Tnode[p].sum;
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(e<=mid)
        return Query(lch(p),s,e);
    else if(s>mid)
        return Query(rch(p),s,e);
    else
        return Query(lch(p),s,mid)+Query(rch(p),mid+1,e);
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%I64d",&W[i]);
    scanf("%d",&M);
}
void Solve()
{
    int i,s,e,kind,t;
    printf("Case #%d:\n",cas++);
    Build(1,1,N);
    while(M--)
    {
        scanf("%d%d%d",&kind,&s,&e);
        if(s>e)                 //注意
        {t=s;s=e;e=t;}
        if(kind==0)
            Update(1,s,e);
        else
        {
            type ans=Query(1,s,e);
            printf("%I64d\n",ans);
        }
    }
    printf("\n");
}
int main()
{
    cas=1;
    while(scanf("%d",&N)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}
