////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-30 13:30:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[100]={0};
int f(int n)
{
	int i=1;
	while(n)
	{
		a[i]=n%2;
		n/=2;
		i++;
	}
	return i-1;
}
main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		int m=f(n);
		for(i=m;i>=1;i--)
			printf("%d",a[i]);
		printf("\n");
	}
return 0;
}