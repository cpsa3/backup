////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-13 08:24:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3033
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:624KB
//////////////////System Comment End//////////////////
/*有限制条件的0-1背包*/
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[11][10005];
int P[105],V[105];
int map[11][105];
int len[11];//每类商标的产品数
int N,M,K;
void Init()
{
	int i,x;
	memset(dp,0,sizeof(dp));
	memset(len,0,sizeof(len));
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&x,&P[i],&V[i]);
		map[x][len[x]++]=i;
	}
}
void Solve()
{
	int i,j,k;
	dp[0][0]=1;
	for(i=1;i<=K;i++)
	{
		for(k=0;k<len[i];k++)
		{
			for(j=M-P[map[i][k]];j>=0;j--)
			{
				if(dp[i][j])
					dp[i][j+P[map[i][k]]]=max(dp[i][j+P[map[i][k]]],dp[i][j]+V[map[i][k]]);
				if(dp[i-1][j])
					dp[i][j+P[map[i][k]]]=max(dp[i][j+P[map[i][k]]],dp[i-1][j]+V[map[i][k]]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=M;i++)
		ans=max(ans,dp[K][i]);
	if(ans==0)
		printf("Impossible\n");
	else
		printf("%d\n",ans-1);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}