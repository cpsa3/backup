////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-04 13:00:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2191
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*HDU_2191 悼念512汶川大地震遇难同胞——珍惜现在，感恩生活*/
/*多重背包*/
/*
思路：
(1):状态 dp[i] 表示i元最多能买到的大米斤数
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 105
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int dp[MAXN];
int w[MAXN];
int v[MAXN];
int num[MAXN];
int N,M;

void Init()
{
    int i;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++)
        scanf("%d%d%d",&w[i],&v[i],&num[i]);
}
void Solve()
{
    int i,j,k;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    
    for(i=1;i<=M;i++)
    {
        for(k=1;k<=num[i];k++)
        {
            for(j=N-w[i];j>=0;j--)
            {
                if(dp[j]!=-1)
                    dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
            }
        }
    }
    int ans=0;
    for(i=0;i<=N;i++)
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