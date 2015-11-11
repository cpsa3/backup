////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 11:57:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
int MIN(int a,int b)
{
	return a<b?a:b;
}
__int64 f(int n,int m)
{
	__int64 s=MIN(n,m),i;
	for(i=s;i>=1;i--)
		if(n%i==0&&m%i==0)
			break;
		return n/i*m;
}
main ()
{
	int t,n,i,a[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1)
		{printf("%d\n",a[1]);continue;}
		__int64 s=f(a[1],a[2]);
		for(i=3;i<=n;i++)
			s=f(s,a[i]);
		printf("%I64d\n",s);
	}
	return 0;
}