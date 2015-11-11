////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-25 23:11:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1267
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*DP*/
/*
dp[0][j]=1;
dp[i][j]=dp[i-1][j]+dp[i][j-1];(i<=j)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
__int64 dp[30][30];
int N,M;
void fuck()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=20;i++)
        dp[0][i]=1;
    for(i=1;i<=20;i++)
    {
        for(j=i;j<=20;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}
int main()
{
    fuck();
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        printf("%I64d\n",dp[N][M]);
    }
return 0;
}