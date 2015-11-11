////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-30 22:33:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1421
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:15852KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std; 
int dp[2000][2000];//dp[i][j]��ʾi����Ʒ��ѡ2*j����Ʒ�������Сƣ�Ͷ�
int w[2000];
main ()
{
	int n,k,i,j;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);
		sort(w+1,w+1+n);//������������ķ���һ��(̰��)
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=99999999;
			for(i=0;i<=n;i++)//
				dp[i][0]=0;
			for(i=2;i<=n;i++)//һ��Ҫ��2-n
			{
				for(j=1;j*2<=n;j++)
				{
					if(dp[i-1][j]>dp[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]))
						dp[i][j]=dp[i-2][j-1]+(w[i]-w[i-1])*(w[i]-w[i-1]);
					else
						dp[i][j]=dp[i-1][j];
				}
			}
			printf("%d\n",dp[n][k]);
	}
return 0;
}