////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-28 00:08:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1712
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*DP*/
/*
dp[i][j]:��ʾǰi�ſλ�j��ʱ������ܵõ�ѧ��

ת�Ʒ��̣�dp[i][j]=max(dp[i][j],dp[i-1][j-k]+A[i][k]);
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
    for(i=1;i<=N;i++)//����
    {
        for(j=M;j>=1;j--)//��������
        {
            for(k=1;k<=M;k++)
            {
                if(j>=k)
                dp[j]=max(dp[j],dp[j-k]+A[i][k]);
                //dp[i][j]=max(dp[i][j],dp[i-1][k]+A[i][j-k]);
            }
        }
    }
    int ans=0;
    //for(i=1;i<=N;i++)
    //{
        for(j=1;j<=M;j++)
            ans=max(ans,dp[j]);
    //}
    printf("%d\n",ans);
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