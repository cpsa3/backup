////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-02 14:11:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:280KB
//////////////////System Comment End//////////////////
/*HDU_1013 FATE*/
/*多重背包  O(n^3)*/
/*
思路：
(1):状态表示 dp[i][j] 表示忍耐度为i,杀了j个怪时能获得的最大经验
(2):初始条件 dp[0][0]=0;
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int N,M,K,S;
int dp[105][105];
int v[105];
int c[105];

void Init()
{
    int i;
    for(i=1;i<=K;i++)
        scanf("%d%d",&v[i],&c[i]);
}

void Solve()
{
    int i,j,k;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(i=1;i<=K;i++)
    {
        for(j=0;j<=M-c[i];j++)
        {
            for(k=0;k<S;k++)
            {
                if(dp[j][k]!=-1)
                    dp[j+c[i]][k+1]=max(dp[j+c[i]][k+1],dp[j][k]+v[i]);
            }
        }
    }
    bool ok=false;
    int ans=-1;
    for(i=0;i<=M&&(!ok);i++)
    {
        for(j=0;j<=S;j++)
        {
            if(dp[i][j]>=N)
            {ok=true;ans=i;break;}
        }
    }
    if(!ok) printf("-1\n");
    else printf("%d\n",M-ans);
}
int main()
{
    while(scanf("%d%d%d%d",&N,&M,&K,&S)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}