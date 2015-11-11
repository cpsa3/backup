////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-10-02 13:51:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:8860KB
//////////////////System Comment End//////////////////
/*HDU_1011 ����ڱ�*/
/*��άDP  ˳�� O(n)*/
/*
˼·��
(1):״̬��ʾ dp[i][j]��ʾ��i����jλ���ܻ�õ�����ڱ���
(2):Ԥ����   num[i][j] ��ʾ��i�����jλ�õ��ڱ���
(3):״̬ת��
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+num[i+1][j]);
                if(j<=9)
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+num[i+1][j+1]);
                if(j>=1)
                dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+num[i+1][j-1]);
(4):��ʼ����    dp[0][5]=0;
                ����ȫΪ-1
*/

#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N,Max_T;
int Num[MAXN][11];
int dp[MAXN][11];

void Init()
{
    int i,j,x,t;
    Max_T=0;
    memset(Num,0,sizeof(Num));
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&x,&t);
        Num[t][x]++;
        Max_T=max(Max_T,t);
    }
}
void Solve()
{
    int i,j;
    for(i=0;i<=Max_T;i++)
    {
        for(j=0;j<=10;j++)
            dp[i][j]=-1;
    }
    dp[0][5]=0;
    for(i=0;i<=Max_T;i++)
    {
        for(j=0;j<=10;j++)
        {
            if(dp[i][j]==-1) continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+Num[i+1][j]);
            if(j<=9)
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+Num[i+1][j+1]);
            if(j>=1)
                dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+Num[i+1][j-1]);
        }
    }
    int ans=0;
    for(i=0;i<=10;i++)
        ans=max(ans,dp[Max_T][i]);
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}