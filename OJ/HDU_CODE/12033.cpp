////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-02 12:32:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:340KB
//////////////////System Comment End//////////////////
/*HDU_1203 I NEED A OFFER!*/
/*0-1背包*/
/*
(1):状态：dp[i]表示i元能获得的最大录取率
(2):状态转移：dp[j+w[i]]=max(dp[j]+w[i],1-(1-dp[j])*(1-p[j]))；
(3):初始条件：dp[0]=0;
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 10005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N,M;
double dp[MAXN];
double p[1005];
int w[1005];

void Init()
{
    int i;
    for(i=1;i<=M;i++)
        scanf("%d%lf",&w[i],&p[i]);
}
void Solve()
{
    int i,j;
    for(i=0;i<=N;i++)
        dp[i]=-1;
    dp[0]=0;
    for(i=1;i<=M;i++)
    {
        for(j=N-w[i];j>=0;j--)
        {
            if(dp[j]!=-1)
            {
                //double t=1-(1-dp[j])*(1-p[i]);
                //dp[j+w[i]]=max(dp[j+w[i]],t);
                dp[j+w[i]]=max(dp[j+w[i]],1-(1-dp[j])*(1-p[i]));
            }
        }
    }
    double ans=0;
    for(i=0;i<=N;i++)
        ans=max(ans,dp[i]);
    printf("%.1lf%%\n",ans*100);
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