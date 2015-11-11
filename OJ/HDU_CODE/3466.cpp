////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-27 01:35:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3466
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*0-1背包(加了点限制)*/
/*先按：Q-P从小到大排序*/
/*AC代码：32ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 5005
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int p,q,v;
    int key;
}node[600];
int dp[MAXN];
int N,M;
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p2)->key-((struct Node *)p1)->key;
}
void Print()
{
    int i;
    for(i=1;i<=N;i++)
        printf("%d %d %d\n",node[i].p,node[i].q,node[i].v);
    printf("**************\n");
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%d",&node[i].p,&node[i].q,&node[i].v);
        node[i].key=node[i].q-node[i].p;
    }
    qsort(node+1,N,sizeof(node[0]),cmp);
    //Print();
}
void Solve()
{
    int i,j;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=1;i<=N;i++)
    {
        for(j=M-max(node[i].p,node[i].q);j>=0;j--)
        {
            if(dp[j]!=-1)
                dp[j+node[i].p]=max(dp[j+node[i].p],dp[j]+node[i].v);
        }
    }
    int ans=0;
    for(i=0;i<=M;i++)
        ans=max(ans,dp[i]);
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