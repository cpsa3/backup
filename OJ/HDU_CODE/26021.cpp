////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-28 20:11:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*HDU_2602 Bone Collector*/
/*0-1±³°ü*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 1005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int w[MAXN];
int v[MAXN];
int dp[MAXN];
int N,V;

void Init()
{
    int i;
    scanf("%d%d",&N,&V);
    for(i=1;i<=N;i++)
        scanf("%d",&v[i]);
    for(i=1;i<=N;i++)
        scanf("%d",&w[i]);
}
void Solve()
{
    int i,j;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=1;i<=N;i++)
    {
        for(j=V-w[i];j>=0;j--)
            if(dp[j]!=-1) dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
    }
    int ans=0;
    for(i=1;i<=V;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}