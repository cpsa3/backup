////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-28 00:55:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3732
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*多重背包+二进制压缩*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[10005];
int N,C,cnt;
int v[100005],c[100005];
int map[11][11];
void fuck()//二进制压缩
{
    int i,j,sum,t;
    cnt=0;
    for(i=0;i<=10;i++)
    {
        for(j=0;j<=10;j++)
        {
            if(map[i][j]>=1)
            {
                sum=1;t=1;
                while(sum<=map[i][j])
                {
                    v[cnt]=i*t;
                    c[cnt]=j*t;
                    cnt++;
                    t<<=1;
                    sum+=t;
                }
                if((sum-t)<map[i][j])//还有多余
                {
                    v[cnt]=i*(map[i][j]-(sum-t));
                    c[cnt]=j*(map[i][j]-(sum-t));
                    cnt++;
                }
            }
        }
    }
}
void Init()
{
    int i,a,b;
    char s[20];
    memset(map,0,sizeof(map));
    for(i=1;i<=N;i++)
    {
        scanf("%s%d%d",s,&a,&b);
        map[a][b]++;
    }
    fuck();//二进制压缩
}
void Print()
{
    int i;
    for(i=0;i<cnt;i++)
        printf("%d %d\n",v[i],c[i]);
    printf("************\n");
}
void Solve()
{
    int i,j;
    //Print();
    memset(dp,0,sizeof(dp));
    for(i=0;i<cnt;i++)
    {
        for(j=C-c[i];j>=0;j--)
        {
            dp[j+c[i]]=max(dp[j+c[i]],dp[j]+v[i]);
        }
    }
    int ans=0;
    for(i=0;i<=C;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&N,&C)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}