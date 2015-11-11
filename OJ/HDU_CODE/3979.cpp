////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-26 20:18:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3979
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:708KB
//////////////////System Comment End//////////////////
/*Ì°ÐÄ*/
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define INF 1e8
#define MAXN 10005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    __int64 hp,g,id,x;
    double key;
}node[MAXN];
__int64 N,M,cas;
__int64 sum[MAXN];
int cmp(const void *p1,const void *p2)
{
   if(((struct Node *)p1)->key>((struct Node *)p2)->key)
        return -1;
   else if(((struct Node *)p1)->key<((struct Node *)p2)->key)
        return 1;
   return 0;
}
void fuck()
{
    __int64 i,j,x,y;
    for(i=1;i<=N;i++)
    {
        x=node[i].hp/M;
        y=node[i].hp%M;
        if(y!=0) x++;
        node[i].x=x;
        node[i].key=node[i].g*1.0/x;
    }
    /*
    for(i=1;i<=N;i++)
    printf("%I64d ",node[i].key);
    printf("\n");
    */
    qsort(node+1,N,sizeof(node[0]),cmp);
    memset(sum,0,sizeof(sum));
    sum[N]=node[N].g;
    for(i=N-1;i>=1;i--)
        sum[i]=sum[i+1]+node[i].g;
}
void Print()
{
    int i;
    for(i=1;i<=N;i++)
    printf("%d ",node[i].id);
    printf("\n");
}
void Init()
{
    int i;
    scanf("%I64d%I64d",&N,&M);
    for(i=1;i<=N;i++)
    {
        scanf("%I64d%I64d",&node[i].hp,&node[i].g);
        node[i].key=0;
        node[i].id=i;
    }
    fuck();
}
void Solve()
{
    __int64 i,ans=0,x;
    //Print();
    for(i=1;i<=N;i++)
    {
        x=node[i].x;
        ans+=x*sum[i];
    }
    printf("Case #%I64d: %I64d\n",cas++,ans);
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