////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-05-22 11:28:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1573
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
__int64 N,M;
__int64 a[11],b[11];
__int64 gcd(__int64 a,__int64 b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
bool Judge(__int64 x)
{
	int i;
	bool ok=true;
	for(i=1;i<=M;i++)
	{
		if(x%a[i]!=b[i])
		{ok=false;break;}
	}
	return ok;
}
int main()
{
	int T;
	__int64 i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&N,&M);
		for(i=1;i<=M;i++)
			scanf("%I64d",&a[i]);
		for(i=1;i<=M;i++)
			scanf("%I64d",&b[i]);
		__int64 sum=1;
		for(i=1;i<=M;i++)
			sum=sum*a[i]/gcd(sum,a[i]);
		int t=0;
		for(i=1;i<=sum;i++)
		{
			if(Judge(i)) {t=1;break;}
		}
		if(t==0) {printf("0\n");continue;}//◊¢“‚
		__int64 ans=0;
		for(;i<=N;i+=sum)
			ans++;
		printf("%I64d\n",ans);

	}
return 0;
}
