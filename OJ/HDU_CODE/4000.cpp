////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-02 20:19:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4000
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:6300KB
//////////////////System Comment End//////////////////
/*Ïß¶ÎÊ÷*/
/*ans=(xyz+xzy)-xyz;*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
#define MOD 100000007
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
    int s,e;
    __int64 v;
}Tnode[4*MAXN];
int W[MAXN],N,cas;
__int64 L[MAXN],R[MAXN];
void Build(int p,int s,int e)
{
    Tnode[p].s=s;Tnode[p].e=e;
    Tnode[p].v=0;
    if(s==e) return;
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
}
__int64 Insert_L(int p,int k)
{
    Tnode[p].v++;
    if(Tnode[p].s==Tnode[p].e)
        return Tnode[p].v-1;
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k<=mid)
        return Insert_L(lch(p),k);
    else
        return Tnode[lch(p)].v+Insert_L(rch(p),k);
}
__int64 Insert_R(int p,int k)
{
    Tnode[p].v++;
    if(Tnode[p].s==Tnode[p].e)
        return Tnode[p].v-1;
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    if(k>mid)
        return Insert_R(rch(p),k);
    else
        return Tnode[rch(p)].v+Insert_R(lch(p),k);
}
void Init()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&W[i]);
}
void Solve()
{
    int i;
    Build(1,1,N);
    for(i=1;i<=N;i++)
        L[i]=Insert_L(1,W[i]);
    Build(1,1,N);
    for(i=N;i>=1;i--)
        R[i]=Insert_R(1,W[i]);
    __int64 ans=0;
    for(i=1;i<=N;i++)
    {
        ans=ans+((R[i]*(R[i]-1))>>1)-L[i]*R[i];
        ans%=MOD;
    }
    ans=(ans+MOD)%MOD;
    printf("Case #%d: %I64d\n",cas++,ans);
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