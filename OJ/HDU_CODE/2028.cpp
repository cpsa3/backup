////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 22:10:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int MIN(int a,int b)
{
	return a<=b?a:b;
}
int f(int a,int b)
{
	int m=MIN(a,b),i;
	for(i=m;i>=1;i--)
		if(a%i==0&&b%i==0)
			break;
		return a/i*b;
}
main ()
{
	int t,i;
	while(scanf("%d",&t)!=EOF)
	{
		int a[100];
		for(i=1;i<=t;i++)
			scanf("%d",&a[i]);
		if(t==1)
		{printf("%d\n",a[1]);continue;}
		int w=f(a[1],a[2]);
		for(i=3;i<=t;i++)
			w=f(w,a[i]);
		printf("%d\n",w);
	}
return 0;
}