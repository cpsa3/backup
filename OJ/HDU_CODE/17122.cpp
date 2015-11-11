////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-28 00:11:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1712
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*DP*/
/*
dp[i][j]:表示前i门课化j天时间最多能得的学分

转移方程：dp[i][j]=max(dp[i][j],dp[i-1][j-k]+A[i][k]);

分组背包  .

思路：

for 所有的组k

    for v=V..0

        for 所有的i属于组k

           if(v>=c[k]) f[v]=max{f[v],f[v-c[i]]+w[i]}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int dp[105];
int N,M;
int A[105][105];
void Init()
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&A[i][j]);
    }
}
void Solve()
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=N;i++)//分组
    {
        for(j=M;j>=1;j--)//背包容量
        {
            for(k=1;k<=M;k++)//不同时间的课程
            {
                if(j>=k)
                dp[j]=max(dp[j],dp[j-k]+A[i][k]);
            }
        }
    }
    printf("%d\n",dp[M]);
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N==0&&M==0) break;
        Init();
        Solve();
    }
return 0;
}