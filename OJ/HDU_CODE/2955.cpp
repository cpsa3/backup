////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-09-28 20:54:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2955
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*HDU_2955 Robberies*/
/*0-1���� (�Ի�ö���Ǯ��Ϊ�±�)*/
/*
(1):״̬ O(N*M)��        dp[i]:��ʾ���iԪ���ܵ���С�����ʡ�
(2):״̬ת�� O(1)��      dp[j+v[i]]=min(dp[j+v[i]],1-(1-dp[j])*(1-p[i]));
(3):��ʼ������           dp[0]=0;
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#define MAXN 10005
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

double dp[MAXN];
double p[105];
int v[105];
int N,Sum;
double P;

void Init()
{
    int i;
    scanf("%lf%d",&P,&N);
    Sum=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d%lf",&v[i],&p[i]);
        Sum+=v[i];
    }
}
void Solve()
{
    int i,j;
    for(i=0;i<=Sum;i++)
        dp[i]=1;
    dp[0]=0;
    
    for(i=1;i<=N;i++)
    {
        for(j=Sum-v[i];j>=0;j--)
        {
            if(dp[j]!=-1)
                dp[j+v[i]]=min(dp[j+v[i]],1-(1-dp[j])*(1-p[i]));
        }
    }
    int ans=0;
    for(i=Sum;i>=1;i--)
    {
        if(dp[i]<P)
        {ans=i;break;}
    }
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