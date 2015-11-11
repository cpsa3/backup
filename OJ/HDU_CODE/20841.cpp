////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-28 19:48:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:308KB
//////////////////System Comment End//////////////////
/*HDU_2084 数塔*/
/*DP*/
/*
(1):状态 O(n^2)     :dp[i][j]:从(i,j)到底层所能获得的最大分数
(2):状态转移 O(1)   :dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+W[i][j];
(3):初始条件        :dp[i][j]=W[i][j];  当i==N时
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 105
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int dp[MAXN][MAXN];
int W[MAXN][MAXN];
int N;

void Init()
{
    int i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=i;j++)
            scanf("%d",&W[i][j]);
    }
}
void Solve()
{
    int i,j;
    for(i=N;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            if(i==N) {dp[i][j]=W[i][j];continue;}
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+W[i][j];
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