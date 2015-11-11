////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-01 19:39:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1505
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
#include <iostream>
int dp[1001][1001],l[1001],r[1001];
char a[3];
main ()
{
	int T,n,m,temp,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(j=0;j<=m;j++)//初始化
			dp[0][j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%s",a);
				if(a[0]=='F')
				dp[i][j]=dp[i-1][j]+1;
				else
					dp[i][j]=0;
			}
		}
		int max=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				l[j]=r[j]=j;
			dp[i][0]=dp[i][m+1]=-1;
			for(j=2;j<=m;j++)//向左处理
			{
				while(dp[i][j]<=dp[i][l[j]-1])//如果左边的高度大于当前的，则当前的左边界向左移
					l[j]=l[l[j]-1];
			}

			for(j=m-1;j>=1;j--)//向右处理
			{
				while(dp[i][j]<=dp[i][r[j]+1])//如果右边的高度大于当前的，则当前的右边界向左移
					r[j]=r[r[j]+1];
			}

			for(j=1;j<=m;j++)//水平遍历
			{
				temp=dp[i][j]*(r[j]-l[j]+1);
				if(temp>max)
					max=temp;
			}
		}
		printf("%d\n",max*3);	
	}
	return 0;
}