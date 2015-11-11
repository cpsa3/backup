////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-05 13:28:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:284KB
//////////////////System Comment End//////////////////
/*HDU_1114 Piggy-Bank*/
/*∂‡÷ÿ±≥∞¸*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 10005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int dp[MAXN];
int w[505];
int v[505];
int N,F,E,M;

void Init()
{
    int i;
    scanf("%d%d",&E,&F);
    M=F-E;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d%d",&v[i],&w[i]);
}
void Solve()
{
    int i,j;
    for(i=0;i<=M;i++)
        dp[i]=INF;
    dp[0]=0;
    for(i=1;i<=N;i++)
    {
        for(j=0;j<=M-w[i];j++)
        {
            if(dp[j]!=-1)
                dp[j+w[i]]=min(dp[j+w[i]],dp[j]+v[i]);
        }
    }
    if(dp[M]==INF) printf("This is impossible.\n");
    else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[M]);
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