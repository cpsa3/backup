////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-04 16:16:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4004
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*¶þ·Ö*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 500005
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int L,N,M,l,r,mid;
int W[MAXN];
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d",&W[i]);
    sort(W+1,W+1+N);
    l=0;
    W[0]=0;W[N+1]=L;
    for(i=0;i<=N;i++)
        W[i]=W[i+1]-W[i];
    for(i=0;i<=N;i++)
        l=max(l,W[i]);
}
bool Judge(int mid)
{
    int i,res=0,now=0;
    for(i=0;i<=N;i++)
    {
        if(now+W[i]>mid)
        {
            res++;
            now=W[i];
        }
        else
            now+=W[i];
    }
    if(now>0) res++;
    if(res<=M)
        return true;
    return false;
}
void Solve()
{
    r=L;
    while(l!=r)
    {
        mid=(l+r)>>1;
        if(Judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",l);
}
int main()
{
    while(scanf("%d%d%d",&L,&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}