////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-06 19:30:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3346
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[10005];
int main ()
{
	int T;
	__int64 n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		if(n%8==0)
		{printf("Lucky number!\n");continue;}
		int i=1;
		while(n)
		{
			a[i]=n%10;
			n/=10;
			i++;
		}
		__int64 s=i,ans=0;
		for(i=1;i<s;i++)
			ans+=a[i];
		if(ans%8==0)
		{printf("Lucky number!\n");continue;}
		for(i=1,ans=0;i<s;i++)
			ans+=a[i]*a[i];
		if(ans%8==0)
		{printf("Lucky number!\n");continue;}
		printf("What a pity!\n");
	}
	return 0;
}