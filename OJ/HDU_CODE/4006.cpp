////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-03 18:48:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4006
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:580KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1000005
#define INF 1e9
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
    int s,e,v;
}Tnode[4*MAXN];
int Min,pos,N,K;
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].v=0;
    if(s==e) return ;
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
}
void Query(int p,int x)
{
    if(Tnode[p].s==Tnode[p].e)
    {
        Min=Tnode[p].v;
        pos=Tnode[p].s;
        if(Min<x) Tnode[p].v=x;
        return ;
    }
    if(Tnode[lch(p)].v<=Tnode[rch(p)].v)
        Query(lch(p),x);
    else
        Query(rch(p),x);
    Tnode[p].v=min(Tnode[lch(p)].v,Tnode[rch(p)].v);
}
int main()
{
    int x,i;
    char s[3];
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        Build(1,1,K);
        while(N--)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%d",&x);
                Query(1,x);
            }
            else
            {
                Query(1,-INF);
                printf("%d\n",Min);
            }
        }
    }
return 0;
}