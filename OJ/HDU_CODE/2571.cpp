////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-26 23:43:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:348KB
//////////////////System Comment End//////////////////
/*DP*/
/*AC´úÂë£º0ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define INF 1e8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int dp[30][1005];
int N,M;
void Init()
{
    int i,j;
    scanf("%d%d",&N,&M);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&dp[i][j]);
    }
}
void Solve()
{
    int i,j,k,Max;
    for(i=N;i>=1;i--)
    {
        for(j=M;j>=1;j--)
        {
            if(i==N&&j==M) continue;
            Max=-INF;
            if(i<N) Max=dp[i+1][j];
            if(j<M) Max=max(Max,dp[i][j+1]);
            for(k=2;k*j<=M;k++)
                Max=max(Max,dp[i][j*k]);
            dp[i][j]+=Max;
        }
    }
    printf("%d\n",dp[1][1]);
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