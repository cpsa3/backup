////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-22 23:38:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*∆⁄Õ˚Ã‚*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int N;
__int64 gcd(__int64 n,__int64 m)
{
	if(m==0) return n;
	return gcd(m,n%m);
}
int len(__int64 x)
{
	int res=0;
	while(x)
	{
		res++;
		x/=10; 
	}
	return res;
}
int main()
{
	__int64 a,b,d;
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		a=1;b=N;
		for(i=2;i<=N;i++)
		{
			b=b*i+a*N;
			a=a*i;
			d=gcd(b,a);
			b/=d;
			a/=d; 
		}
		d=b/a;
		b%=a;
		if(b==0)
			printf("%I64d\n",d);
		else
		{
			int len1=len(d);
			int len2=len(a);
			for(i=0;i<=len1;i++)
				printf(" ");
			printf("%I64d\n",b);
			printf("%I64d ",d);
			for(i=1;i<=len2;i++)
				printf("-");
			printf("\n");
			for(i=0;i<=len1;i++)
				printf(" ");
			printf("%I64d\n",a); 
		} 

	}
return 0;
}