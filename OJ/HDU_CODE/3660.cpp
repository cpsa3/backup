////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-14 10:35:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3660
////Problem Title: 
////Run result: Accept
////Run time:1796MS
////Run memory:17840KB
//////////////////System Comment End//////////////////
/**HDU_3660 Alice and Bob's Trip/
/*树形DP*/
/*注意：
(1):深搜时要记录当前点到root的距离len
(2):只有当len+w+dp[v]>=L&&len+w+dp[v]<=R时才更新答案
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 500005
#define INF 2000000000
#define type __int64
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
    int u,v,next;
    type w;
}E[MAXN+5];
int head[MAXN],ecnt;
int N;
type L,R,dp[MAXN];
bool ok;
void Insert(int u,int v,type w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,u,v;
    type w;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<N;i++)
    {
        scanf("%d%d%I64d",&u,&v,&w);
        Insert(u,v,w);
    }
}
void dfs(int u,int d,type len)
{
    int i,v;
    type t,w,ans;
    if(len>R) return;               //剪枝
    if(head[u]==-1) {dp[u]=0;return;}
    if(d%2) dp[u]=-1;
    else dp[u]=INF;
    for(i=head[u];i!=-1;i=E[i].next)
    {
        v=E[i].v;w=E[i].w;
        dfs(v,d+1,len+w);
        t=dp[v]+len+w;
        if(t>R||t<L) continue;
        if(d%2)
            dp[u]=max(dp[u],dp[v]+w);
        else
            dp[u]=min(dp[u],dp[v]+w);
    }
    return;
}
void Solve()
{
    memset(dp,0,sizeof(dp));
    dfs(0,1,0);
    if(dp[0]>R||dp[0]<L) printf("Oh, my god!\n");
    else printf("%I64d\n",dp[0]);
}
int main()
{
    while(scanf("%d%I64d%I64d",&N,&L,&R)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}