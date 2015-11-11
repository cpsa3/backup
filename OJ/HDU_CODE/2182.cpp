////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-02 15:14:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2182
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
//dp[i][k]=max(dp[i+j][k+1])+a[i]----(A<=j<=B)

#include <iostream>
int dp[101][101],N,A,B,K;
int a[101];
main ()
{
	int T,max,i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&N,&A,&B,&K);
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		for(i=0;i<=N;i++)
			for(j=0;j<=K;j++)
			dp[i][j]=0;
		for(i=1;i<=K;i++)
		{
			for(j=0;j<N;j++)
			{
				max=0;
				for(k=j+A;k<=j+B&&k<N;k++)
					if(max<dp[k][i-1]+a[k])
						max=dp[k][i-1]+a[k];
					dp[j][i]=max;
			}
		}
		printf("%d\n",dp[0][K]+a[0]);
	}
	return 0;
}