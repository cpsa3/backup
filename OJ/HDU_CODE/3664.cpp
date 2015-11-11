////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-14 09:55:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3664
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:7140KB
//////////////////System Comment End//////////////////
/*DP*/
/*
dp[i][j]:表示i个里面有j个大与本身
dp[i][j]=dp[i-1][j]*(j+1)+dp[i-1][j-1]*(i-j);
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define type __int64
#define MOD  1000000007
using namespace std;
type dp[MAXN][MAXN];
int N,K;
int main()
{
    int i,j;
    dp[1][0]=1;dp[2][0]=1;dp[2][1]=1;
    for(i=3;i<=1000;i++)
    {
        dp[i][0]=1;
        for(j=1;j<=i-1;j++)
            dp[i][j]=((dp[i-1][j]*(j+1))%MOD+(dp[i-1][j-1]*(i-j))%MOD)%MOD;
    }
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        if(K>N-1) printf("0\n");
        else printf("%I64d\n",dp[N][K]);
    }
return 0;
}