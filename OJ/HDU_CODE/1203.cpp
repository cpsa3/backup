////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-27 00:57:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:336KB
//////////////////System Comment End//////////////////
/*0-1±³°ü*/
/*AC´úÂë£º32ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 10005
using namespace std;
double dp[MAXN];
int N,M;
int w[MAXN];
double v[MAXN];
void Init()
{
    int i;
    for(i=1;i<=M;i++)
        scanf("%d%lf",&w[i],&v[i]);
}
void Solve()
{
    int i,j;
    double t;
    for(i=1;i<=N;i++)
        dp[i]=-1;
    dp[0]=0;
    for(i=1;i<=M;i++)
    {
        for(j=N-w[i];j>=0;j--)
        {
            if(dp[j]!=-1)
            {
                t=1-(1-dp[j])*(1-v[i]);
                dp[j+w[i]]=max(dp[j+w[i]],t);
            }
        }
    }
    double ans=-1;
    for(i=0;i<=N;i++)
        ans=max(ans,dp[i]);
    ans*=100;
    printf("%.1lf%%\n",ans);
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