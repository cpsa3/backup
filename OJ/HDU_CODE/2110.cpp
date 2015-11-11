////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-02 20:13:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2110
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
int p[101],m[101],dp[10005];
main  ()
{
	int i,n,k,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i],&m[i]);
			sum+=p[i]*m[i];
		}
		if(sum%3)
		{printf("sorry\n");continue;}
		sum/=3;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=sum-p[i];j>=0;j--)
			{
				if(dp[j])
					for(k=1;k<=m[i]&&j+k*p[i]<=sum;k++)
						dp[j+k*p[i]]+=dp[j];
			}
			if(dp[sum]) flag=1;
			for(j=1;j<=sum;j++)
				if(dp[j]>=10000) dp[j]%=10000;
		}
		if(flag)
		printf("%d\n",dp[sum]%10000);
		else
		printf("sorry\n");
	}
return 0;
}