////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-08 10:46:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4011
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:2556KB
//////////////////System Comment End//////////////////
/*HDU_4011 Working in Beijing*/
/*DP*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define type __int64
#define INF ((type(1))<<60)
#define MAXN 100005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N,cas;
type day[MAXN],A,B,dp[MAXN][2];//dp[i][0]:第i天回去；dp[i][1]:第i天留在那

void Init()
{
    int i;
    scanf("%d%I64d%I64d",&N,&A,&B);
    for(i=1;i<=N;i++)
        scanf("%I64d",&day[i]);
}
void Solve()
{
    int i,j;
    dp[1][0]=2*A+B;
    dp[1][1]=A+B;
    for(i=2;i<=N;i++)
    {
        dp[i][0]=min(dp[i-1][0]+2*A+B,dp[i-1][1]+(day[i]-day[i-1])*B+A);
        dp[i][1]=min(dp[i-1][0]+A+B,dp[i-1][1]+(day[i]-day[i-1])*B);
    }
    printf("Case #%d: %I64d\n",cas++,dp[N][0]);
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