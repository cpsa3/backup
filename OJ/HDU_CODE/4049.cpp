////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-28 11:29:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4049
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*BOJ_220 Tourism Planning*/
/*状态DP*/
/*复杂度O((2^n)*(n^3))*/
/*AC代码：615ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 11
#define INF (1<<30)
#define GOAL (1<<N)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int V[MAXN][MAXN];
int B[MAXN][MAXN];
int PI[MAXN];
int dp[MAXN][1<<MAXN];
int F[MAXN][1<<MAXN];//F[i][j]:表示在城市i时状态j下的收益V-B+sum(相互间)
int N,M;

void Init()
{
    int i,j;
    for(i=0;i<M;i++)
        scanf("%d",&PI[i]);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            scanf("%d",&V[i][j]);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            scanf("%d",&B[i][j]);
    }
}
void Run()
{
    int i,j,k,m;
    for(i=0;i<M;i++)       //枚举地点
    {
        for(j=0;j<GOAL;j++)//枚举状态
        {
            F[i][j]=0;
            dp[i][j]=-INF;  //初始化
            for(k=0;k<N;k++)//枚举人
            {
                if((j&(1<<k)))
                {
                    F[i][j]+=V[k][i]-PI[i];
                    for(m=k+1;m<N;m++)
                        if(j&(1<<m))
                    F[i][j]+=B[k][m];
                }
            }
        }
    }
}
void Solve()
{
    Run();
    int i,j,k;
    for(i=0;i<M;i++)
    {
        for(j=0;j<GOAL;j++)
        {
            if(i==0) {dp[i][j]=F[i][j];continue;}
            for(k=j;k<GOAL;k++)   //枚举在前一个地点的状态
            {
                if((j&k)==j)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+F[i][j]);
            }
        }
    }
    int ans=0;
    for(i=0;i<GOAL;i++)
        ans=max(ans,dp[M-1][i]);
    if(ans>0) printf("%d\n",ans);
    else printf("STAY HOME\n");
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
