////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 12:59:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[101][101]={0};
int MAX(int a,int b)
{
	return a>=b?a:b;
}
main()
{
	int i,t,n,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
			for(i=n-1;i>=1;i--)
				for(j=1;j<=i;j++)
					a[i][j]+=MAX(a[i+1][j],a[i+1][j+1]);
				printf("%d\n",a[1][1]);
	}
return 0;
}