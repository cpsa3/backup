////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 13:29:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1028KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[1001][201];
main ()
{
	int i,j,t,n;
	f[1][0]=f[2][0]=1;
	for(i=3;i<=1000;i++)
	{
		int temp=0;
		for(j=0;j<=200;j++)
			f[i][j]=f[i-1][j]+f[i-2][j];
		for(j=0;j<200;j++)
		{
			f[i][j+1]+=f[i][j]/10;
			f[i][j]%=10;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		i=200;
		while(!f[n][i]&&i>=0) i--;
		for(;i>=0;i--)
			printf("%d",f[n][i]);
		printf("\n");
	}
return 0;
}