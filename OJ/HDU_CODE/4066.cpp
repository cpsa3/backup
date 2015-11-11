////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-07 17:14:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4066
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
double dp[1600];
void fuck()
{
	int i;
	dp[1]=1;
	double fz=1,fm=2,pre=1;
	for (i=2;i<=1555;i++)
	{
		if (i%2==0&&i>2)
		{
			pre=fz/fm*pre;
			fz+=2;
			fm+=2;
		}
		dp[i]=dp[i-1]+fz/fm*pre;
	}
}
int main()
{
	int T;
	int cas=1,n;
	fuck();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("Case %d: %.6lf\n",cas++,dp[n]);
	}
	return 0;
}