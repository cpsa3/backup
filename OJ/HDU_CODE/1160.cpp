////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-27 00:25:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1160
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*DP*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#define MAXN 1005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int pre[MAXN];
int l[MAXN];
struct Node
{
    int w,s,id;
}node[MAXN];
int cmp(const void *p1,const void *p2)
{
    if(((struct Node *)p1)->w!=((struct Node *)p1)->w)
        return ((struct Node *)p1)->w-((struct Node *)p2)->w;
    else
        return ((struct Node *)p2)->s-((struct Node *)p1)->s;
}
int N,ans;
void Print(int x)
{
    int i,res[MAXN],cnt=0,u;
    u=x;
    while(true)
    {
        res[cnt++]=u;
        if(u==pre[u]) break;
        u=pre[u];
    }
    printf("%d\n",cnt);
    for(i=cnt-1;i>=0;i--)
        printf("%d\n",node[res[i]].id);
}
int main()
{
    N=1;
    int i,j,k,ith,Max;
    while(scanf("%d%d",&node[N].w,&node[N].s)!=EOF)
    {
        node[N].id=N;
        N++;
    }
    N--;
    qsort(node+1,N,sizeof(node[0]),cmp);
    memset(l,0,sizeof(l));
    pre[1]=1;
    l[1]=1;
    ans=Max=1;
    for(i=2;i<=N;i++)
    {
        ith=i;
        k=0;
        for(j=1;j<i;j++)
        {
            if(l[j]+1<=k) continue;
            if(node[j].w<node[i].w&&node[j].s>node[i].s)
            {
                k=l[j]+1;
                ith=j;
            }
        }
        if(ith==i)
        {
            pre[i]=i;
            l[i]=1;
        }
        else
        {
            pre[i]=ith;
            l[i]=l[ith]+1;
        }
        if(l[i]>Max)
        {
            Max=l[i];
            ans=i;
        }
    }
    Print(ans);
return 0;
}


