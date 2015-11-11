////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-28 18:19:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*HDU_2571 命运*/
/*记忆化搜索(顺推)*/
/*
(1):状态：dp[i][j]表示到(i,j)这点到终止点还能获得的最大值;
(2):初始条件：dp[N][M]=W[N][M];
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int dp[25][1005];
int W[25][1005];
int N,M;
void Init()
{
    int i,j;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&W[i][j]);
    }
}
void Solve()
{
    int i,j,k,t;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            dp[i][j]=-INF;
    }
    dp[1][1]=W[1][1];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(i<N) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+W[i+1][j]);
            if(j<M) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+W[i][j+1]);
            for(k=2;k*j<=M;k++)
                dp[i][k*j]=max(dp[i][k*j],dp[i][j]+W[i][k*j]);
        }
    }
    printf("%d\n",dp[N][M]);
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